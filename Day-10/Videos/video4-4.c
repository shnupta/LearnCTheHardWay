#include <stdio.h>
#include <stdlib.h>

//Pointers with functions
//Important:
//	Get address of item &<item_name>
//	Get value of item *<item_name>

void generateTwoRandomNums(int rand1, int rand2) {
	rand1 = rand() % 50 + 1;
	rand2 = rand() % 50 + 1;

	printf("Without pointers function:\n");
	printf("New rand1 in function = %d\n\n", rand1);
	printf("New rand2 in function = %d\n\n", rand2);
}

void pointerRandomNumbers(int * rand1, int * rand2) {
	//star before assigns the value that is at that address
	*rand1 = rand() % 50 + 1;
	*rand2 = rand() % 50 + 1;

	printf("Pointers function:\n");
	printf("New rand1 in function = %d\n\n", *rand1); //access value
	printf("New rand2 in function = %d\n\n", *rand2);
}

void main() {

	int rand1 = 0, rand2 = 0;

	generateTwoRandomNums(rand1, rand2);

	printf("Main before function call\n\n");

	printf("rand1 = %d\n\n", rand1);
	printf("rand2 = %d\n\n", rand2);

	pointerRandomNumbers(&rand1, &rand2);

	printf("Main after function call\n\n");

	printf("rand1 = %d\n\n", rand1);
	printf("rand2 = %d\n\n", rand2);




}