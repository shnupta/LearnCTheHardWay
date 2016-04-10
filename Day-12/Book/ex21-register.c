// register Type Qualifier

//this forces the compiler to keep the variable in a register,
// should probably only use this if you actually know how to optimise

#include <stdio.h>

int main(int argc, char const *argv[])
{
	register int trueNum = 1;
	if(trueNum) {
		printf("The number was true!\n");
	} else {
		printf("Not true\n");
	}
	return 0;
}