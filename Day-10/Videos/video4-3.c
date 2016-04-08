#include <stdio.h>
#include <stdlib.h>

//Accessing arays and element addresses

void main() {

	char * students[4] = {"Sally", "Mark", "Paul", "Sue"};

	for(int i = 0; i < 4; i++) {
		printf("%s : %d\n\n", students[i], &students[i]);
	}

}