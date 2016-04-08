//This video is about ponters: https://www.youtube.com/watch?v=N7MRxREJ4-U&index=5&list=PLGLfVvz_LVvSaXCpKS395wbCcmsmgRea7

//Intro

#include <stdio.h>
#include <stdlib.h>

void main() {
	int rand1 = 12, rand2 = 15;

	printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);

	printf("rand1 = %d : rand2 = %d\n\n", &rand1, &rand2);

	printf("Size of int %d\n\n", sizeof(rand1));

	//pointer to the address of the rand1 variable
	int * pRand1 = &rand1;

	printf("Pointer %p\n\n", pRand1);

	printf("Poiter %d\n\n", pRand1);

	//how to get the actual value at the address that the pointer
	//is pointing to: it's called dereferencing the pointer
	printf("Value %d\n\n", *pRand1);
}