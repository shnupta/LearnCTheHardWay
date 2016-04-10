// unisgned Type Modifier

// an unsigned type modifier changes the type so that it can't contain
//negative numbers, making the a larger upper bound

#include <stdio.h>

int main(int argc, char const *argv[])
{

	//This won't work
	//unsigned willNotWork = -1;


	unsigned int mustBePositive = 96;

	printf("My favourite number is %d\n", mustBePositive);
	return 0;
}
