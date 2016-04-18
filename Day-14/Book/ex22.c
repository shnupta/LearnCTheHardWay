#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age() {
	return THE_AGE;
}

void set_age(int age) {
	THE_AGE = age;
}

double update_ratio(double new_ratio) {
	static double ratio = 1.0;

	double old_ratio = ratio;
	ratio = new_ratio;

	return old_ratio;
}

void print_size() {
	log_info("I think the size is %d", THE_SIZE);
}


// SOME INFO

/*
extern:
	this tells the compiler that the variable exists but is in another
	location (an external location). Typically meaning it's been
	declared in another .c file.

static (declared in file):
	this is almost the inverse of extern and says that this variable
	should only be available to parts inside this .c file and none others

static (declared in function):
	if you declare a static variable in a function it means that the
	variable is only able to be accessed from within the function and
	not outside of it.
*/