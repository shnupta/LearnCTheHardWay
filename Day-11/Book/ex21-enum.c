// enum Data Type

// enums are useful whn a variable could be one of a small set
//of options
//enumerated types work like integers and convert to integers but can
//give you symbolic names for sets

#include <stdio.h>

int main(int argc, char const *argv[])
{
	typedef enum {
		NORTH,
		SOUTH,
		WEST,
		EAST
	} Direction;

	Direction headThisWay = NORTH;

	if(headThisWay == SOUTH) {
		printf("Uh oh, wrong way...\n");
	} else if (headThisWay == EAST) {
		printf("You've ran into some unwanted trouble.\n");
	} else if (headThisWay == WEST) {
		printf("Well done, you've gone back to where you started, dipstick\n");
	} else {
		printf("You've found the treasure!! :D\n");
	}

	return 0;
}