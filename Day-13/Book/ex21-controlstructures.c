//these are a few control structures the book has yet to teach me about (I have understanding of them in other language though)

#include <stdio.h>

int main(int argc, char const *argv[])
{
	//the do-while loop
	//executes the code in the do block while is true
	//not the same as a while as it does the do then checks the while
	printf("\n\n\n");
	printf("DO-WHILE STRUCTURE\n\n");
	int myage = 0;
	printf("I am %d years old.\n", myage);
	do {
		printf("A year passes, I am now %d years old.\n", myage);
		myage++;
	} while(myage <= 15);

	printf("\n\n\n");

	printf("BREAK STRUCTURE\n\n");

	float myheight = 50.0;

	while(myheight < 180.0) {
		myheight += 12.5;
		if (myheight == 100.0) {
			//the break statement causes te loop to break and end early
			break;
		} else {
			printf("You are now %f cm tall.\n", myheight);
		}
	}

	printf("\n\n\n");

	printf("CONTINUE STRUCTURE\n\n");

	long distance = 100;
	long total = 999999;

	while(distance < total) {
		if (distance >= 49999) {
			printf("Only %ld light years to go!\n", total - distance);
			break;
		} else {
			printf("You've still got a long way to go...\n");
			distance += distance * 2;
			continue;
		}
	}

	printf("\n\n\n");

	printf("GOTO STRUCTURE\n\n");

	goto jump;

	printf("La la la, I will be ignored\n");

	jump: printf("You just jumped to a statement!\n");

	return 0;
}