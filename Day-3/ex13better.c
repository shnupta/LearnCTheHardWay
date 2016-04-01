#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("ERROR: You need one argument.\n");
		//this is how you abort a program
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		// I use the ascii code and seen as a char is representable as an int just added 32 to make it lower
		if(letter > 64 && letter < 91){
			letter += 32;
		}

		switch(letter) {
			case 'a':
				printf("%d: 'A'\n", i);
				break;
			case 'e':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
				printf("%d: 'I'\n", i);
				break;
			case 'o':
				printf("%d: 'O'\n", i);
			case 'u':
				printf("%d: 'U'\n", i);
				break;
			case 'y':
				if (i > 2) {
					//it's only y sometimes
					printf("%d: 'Y'\n", i);
				}
				break;
			default:
				printf("%d: %c is not a vowel.\n", i, letter);
		}
	}

	return 0;
}