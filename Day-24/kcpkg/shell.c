#include "shell.h"
#include "dbg.h"
#include <stdarg.h>

int Shell_exec(Shell template, ...) {
	apr_pool_t *p = NULL; //make an empty apr pool type
	int rc = -1; //set beginning return code to -1
	apr_status_t rv = APR_SUCCESS; //set beginning return variable to a success
	va_list argp; //setup a list
	const char *key = NULL;
	const char *arg = NULL;
	int i = 0;

	rv = apr_pool_create(&p, NULL); //create the pool
	check(rv == APR_SUCCESS, "Failed to create pool."); //make sure its created

	/*
	So this is what I've been stuck with for as while
	as it's pretty complicated (for me anyway). Thankfully
	enough, Zed, the writer of Learn C The Hard Way, helped
	me by explaining basically what this part does. So I'll
	try to comment what I can fatham from his explanation.
	*/


	//we use macros from the stdarg.h file
	//they take the "..." part of this functioin
	//when you call a function, there's a stack.
	//So the parameter given to va_start is 
	// how you say, 'everything after this parameter is part of the stack with ...'
	va_start(argp, template);


	//this loop is just pointing to each piece of the stack and 
	//going through them.
	for(key = va_arg(argp, const char *); //iterate through the list
		key != NULL;
		//the second part of va_arg is the size of the data and it's type
		//this is so va_arg knows to move the right amount to read each piece of data
		key = va_arg(argp, const char *)) {
		
		arg = va_arg(argp, const char *);

		for(i = 0; template.args[i] != NULL; i++) {
			if(strcmp(template.args[i], key) == 0) {
				template.args[i] = arg; //put into the shell template the args that are passed to this function
				break; //found it
			}
		}

	}

	/*
	To figure out what exactly it's doing. I'll add some prints
	when I've finished the whole program.
	*/


	//this is just cleanup of resources and tell the shell to run
	rv = Shell_run(p, &template);
	apr_pool_destroy(p);
	va_end(argp);
	return rc;

error:
	if(p) {
		apr_pool_destroy(p);
	}
	return rc;
}


int Shell_run(apr_pool_t *p, Shell *cmd) {
	apr_procattr_t *attr;
	apr_status_t rv;
	apr_proc_t newproc;

	rv = apr_procattr_create(&attr, p);
	check(rv == APR_SUCCESS, "Failed to create proc attr.");

	rv = apr_procattr_io_set(attr, APR_NO_PIPE, APR_NO_PIPE,
		APR_NO_PIPE);
	check(rv == APR_SUCCESS, "Failed to set IO of command.");

	rv = apr_procattr_dir_set(attr, cmd->dir);
	check(rv == APR_SUCCESS, "Failed to set root to %s", cmd->dir);

	rv = apr_procattr_cmdtype_set(attr, APR_PROGRAM_PATH);
	check(rv == APR_SUCCESS, "Failed to set cmd type.");

	rv = apr_proc_create(&newproc, cmd->exe, cmd->args, NULL, attr, p);
	check(rv == APR_SUCCESS, "Failed to run command.");

	rv = apr_proc_wait(&newproc, &cmd->exit_code, &cmd->exit_why, APR_WAIT);
	check(rv == APR_CHILD_DONE, "Failed to wait.");

	check(cmd->exit_code == 0, "%s exited badly.", cmd->exe);
	check(cmd->exit_why == APR_PROC_EXIT, "%s was killed or crashed.", cmd->exe);

	return 0;

error:
	return -1;


}


Shell CLEANUP_SH = {
    .exe = "rm",
    .dir = "/tmp",
    .args = {"rm", "-rf", "/tmp/pkg-build", "/tmp/pkg-src.tar.gz",
        "/tmp/pkg-src.tar.bz2", "/tmp/DEPENDS", NULL}
};

Shell GIT_SH = {
    .dir = "/tmp",
    .exe = "git",
    .args = {"git", "clone", "URL", "pkg-build", NULL}
};

Shell TAR_SH = {
    .dir = "/tmp/pkg-build",
    .exe = "tar",
    .args = {"tar", "-xzf", "FILE", "--strip-components", "1", NULL}
};

Shell CURL_SH = {
    .dir = "/tmp",
    .exe = "curl",
    .args = {"curl", "-L", "-o", "TARGET", "URL", NULL}
};

Shell CONFIGURE_SH = {
    .exe = "./configure",
    .dir = "/tmp/pkg-build",
    .args = {"configure", "OPTS", NULL},
};

Shell MAKE_SH = {
    .exe = "make",
    .dir = "/tmp/pkg-build",
    .args = {"make", "OPTS", NULL}
};

Shell INSTALL_SH = {
    .exe = "sudo",
    .dir = "/tmp/pkg-build",
    .args = {"sudo", "make", "TARGET", NULL}
};