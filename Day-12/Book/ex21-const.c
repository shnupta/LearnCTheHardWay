// const Type  Qualifier

//a constant means the variable won't change after being initialised

#include <stdio.h>

int main(int argc, char const *argv[])
{
	const char *myName = "Casey";

	printf("My name is %s\n", myName);
	return 0;
}