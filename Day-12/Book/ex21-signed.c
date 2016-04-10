// signed Type Modifier

//signed means you can have a positive and negative value but the bounds
//are half as much as the upper bound of unsigned value in exchange 
//for negative and positive

#include <stdio.h>

int main(int argc, char const *argv[])
{
	signed int above = 1076;
	signed int below = -6533;

	printf("The sum of %d - %d is %d\n", above, below, (above - below));

	return 0;
}