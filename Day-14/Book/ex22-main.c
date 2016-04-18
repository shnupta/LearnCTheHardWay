// Exercise 22: The Stack, Scope, And Globals

#include "ex22.c"
#include "dbg.h"

const char *MY_NAME = "Casey J. Williams"; //const meaning it wont be changed


void scope_demo(int count) { //demonstrates scope issues within functions
	log_info("Count is: %d", count); //prints input count

	if(count > 10) { //new scope block
		int count = 100; //BAD! BUGS! (it is a whole new variable)

		log_info("Count in this scope is: %d", count);
	}

	log_info("Count is at exit: %d", count); //will print parameter value also

	count = 3000; //reassigns the value of the parameter count

	log_info("Count after assignment: %d", count); //prints it out

}

int main(int argc, char const *argv[])
{
	//test out THE_AGE accessors
	log_info("My name is: %s, age: %d", MY_NAME, get_age());

	set_age(100);

	log_info("My age is now: %d", get_age());

	//test out THE_SIZE accessors
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;

	log_info("THE_SIZE is now: %d", THE_SIZE);
	print_size();


	//test out the ratio static function
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio at second: %f", update_ratio(10.0));
	log_info("Ratio at third: %f", update_ratio(300.0));

	//test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("Count after calling scope_demo: %d", count);


	return 0;
}