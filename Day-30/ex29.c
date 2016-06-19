#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data, int msg_length);

int main(int argc, char *argv[]) 
{
	int rc = 0;
	check(argc == 4 || argc == 5, "USAGE: ex29 libex29.so function data string_length.");

	char *lib_file = argv[1];
	char *func_to_run = argv[2];
	char *data = argv[3];
	char *msg_length = atoi(argv[4]);

	void *lib = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());
	lib_function func = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in %s: %s", func_to_run, lib_file, dlerror());

	rc = func(data, msg_length);
	check(rc == 0, " Function %s returned %d for data: %s", func_to_run, rc, data);

	return 0;

error:
	return -1;
}