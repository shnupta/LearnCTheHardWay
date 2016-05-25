#ifndef _shell_h
#define _shell_h

#define MAX_COMMAND_ARGS 100

#include <apr_thread_proc.h> //using this library to run programs like curl and tar

typedef struct Shell { //make the template shell system
	const char *dir;
	const char *exe;

	apr_procattr_t *attr; //the opaque process attributes structure???(no idea?!?)
	apr_proc_t proc; //apr process type (still not sure?)
	apr_exit_why_e exit_why; //enum to tell you why the process has exited
	int exit_code;

	const char *args[MAX_COMMAND_ARGS];
} Shell;

//forward declaration of functions
int Shell_run(apr_pool_t *p, Shell *cmd);
int Shell_exec(Shell cmd, ...);

//external Shell structs that will live in the shell.c file
extern Shell CLEANUP_SH;
extern Shell GIT_SH;
extern Shell TAR_SH;
extern Shell CURL_SH;
extern Shell CONFIGURE_SH;
extern Shell MAKE_SH;
extern Shell INSTALL_SH;

#endif
