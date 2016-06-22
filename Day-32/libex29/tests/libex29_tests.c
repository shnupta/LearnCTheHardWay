#include "minunit.h"


typedef int (*lib_function)(const char *data);
char *lib_file = "build/libex29.so";
void *lib = NULL;

int check_function(const char *func_to_run, const char *data, int expected)
{
	lib_function func = dslym(lib, func_to_run);
	check(func != NULL, "Did not find %s function in %s library: %s.", func_to_run, lib_file, dlerror());

	int rc = func(data);
	check(rc == expected, "Function %s returned %d for data: %s", func_to_run, rc, data);

	return 1;

error:
	return 0;
}


//CONTINUE FROM HERE

char *test_dlopen()
{
	return NULL;
}

char *test_functions()
{
	return NULL;
}

char *test_failures()
{
	return NULL;
}

char *test_dlclose()
{
	return NULL;
}

char *all_tests() {
	mu_suite_start();

	mu_run_test(test_dlopen);
	mu_run_test(test_functions);
	mu_run_test(test_failures);
	mu_run_test(test_dlclose);

	return NULL;
}

RUN_TESTS(all_tests);