#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1) {
		printf("You have no arguments.\n"); //fixed to tell the user their arguments
	} else if (argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");

		for(i = 1; i < argc; i++) {
			printf("%s\n", argv[i]);
		}
	} else {
		printf("You have loads of arguments.\n");
	}

	return 0;
}