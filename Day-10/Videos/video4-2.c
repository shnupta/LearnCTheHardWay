#include <stdio.h>
#include <stdlib.h>

//Pointer arithmetic and accessing array elements

void main() {

	int primeNumbers[] = {2, 3, 5, 7};

	printf("Indexing\n");
	printf("First index: %d\n\n", primeNumbers[0]);

	//here we can also print the first element of the array
	//by using the asterisk, this is because the pointer
	//actually points to the address and that is the first
	//value of the array
	printf("Pointer\n");
	printf("First index: %d\n\n", *primeNumbers);

	printf("Indexing\n");
	printf("Second index: %d\n\n", primeNumbers[1]);

	//you can also do pointer arithmetic to access other elements
	//in the array, by adding one we effectively move on 4 bytes
	//(as the data type is an int) from the pointer address
	printf("Pointer\n");
	printf("Second index: %d\n\n", *(primeNumbers + 1));


}