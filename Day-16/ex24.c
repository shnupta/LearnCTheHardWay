/*
WHY I'VE BEEN AWAY:
So you may have noticed I haven't really completed an exercise of
LearnCTheHardWay in a while. That's because of two main reasons:
One - I decided to go ahead and give making a little emulator in C a go 
(you can check this out in my other repo called Chip-Emul8). Two - 
I've got some exams coming up in the next few weeks so I'm spending
more time revising for those at the moment. Afterwards I will 
continue at a good pace hopefully :)


SOME INFO ABOUT THIS EXERCISE:
fscanf - which is the 'file scanf' function.
		 it's like the opposite of 'printf' and reads in
*/



#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {"Blue", "Green", "Brown", "Black", "Other"};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;

int main(int argc, char const *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;

	printf("What's your first name?\n");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read first name.");

	printf("What's your last name?\n");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read last name.");

	printf("How old are you?\n");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc > 0, "You have to enter a valid number.");

	printf("What colour are your eyes?\n");
	for(i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf("> \n");

	int eyes = -1;
	rc = fscanf(stdin, "%d", &eyes);
	check(you.eyes <= OTHER_EYES, "You have to enter a number.");

	you.eyes = eyes -1;
	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it correctly.");

	printf("How much do you make an hour?\n");
	rc = fscanf(stdin, "%f", &you.income);
	check(rc > 0, "Enter a floating point number.");

	printf("------RESULTS------\n");

	printf("First Name: %s", you.first_name);
	printf("Last Name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;

error:
	return -1;
}




/*
The I/O Functions
This is a short list of various I/O functions that you should look 
up and create index cards that have the function name, what it 
does, and all the variants similar to it.

fscanf
fgets
fopen
freopen
fdopen
fclose
fcloseall
fgetpos
fseek
ftell
rewind
fprintf
fwrite
fread
*/