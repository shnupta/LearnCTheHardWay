// volatile Type Qualifier

//volatile means that the compiler should leave this alone and not try
//to optimise it.

#include <stdio.h>

int main(int argc, char const *argv[])
{
	volatile char * string = "I'm VOLATILE!";

	printf("Look at this: %s\n", string);

	return 0;
}