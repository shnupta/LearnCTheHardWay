#include <stdio.h>

void print_addresses(char *point)
{
	//print the pointer addresses
	printf("%p\n", point);
}



int main(int argc, char *argv[])
{
	//point to a pointer to a char[] in argv
	char **point_args = argv;

	//iterate through and print out each arg from the pointer
	for (int i = 1; i < argc; i++) {
		printf("%s\n", point_args[i]);
	} 

	printf("---------\n");

	//prints by pointing to the address of args + i
	for (int i = 1; i < argc; i++) {
		printf("%s\n", *(point_args+i));
	}

	printf("---------\n");

	//print out the pointer address for each element
	for (int i = 0; i <argc; i++) {
		printf("%p\n", point_args[i]);
	}

	printf("---------\n");

	//pass the pointers to a function
	for (int i = 0; i <argc; i++) {
		print_addresses(point_args[i]);	
	}

	return 0;
}