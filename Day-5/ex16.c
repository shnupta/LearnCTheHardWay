//a task was to try and explain what every line does before it is explained to me, all the comments are mine

#include <stdio.h> //gives access to basic i/o operations
#include <assert.h> //library to test true/false of expressions
#include <stdlib.h> //general purpose library for things like dynamic memory allocation
#include <string.h> //library for manipulating strings

struct Person { //call a structure Person
	char *name; //Person can have an element/field named name that is a string (array of bytes/chars)
	int age; //has an int field called age
	int height; //has an int field called height
	int weight; //has an int field called weight
};

struct Person *Person_create(char *name, int age, int height, int weight) //this is a function called person_create that returns a Person struct
{
	struct Person *who = malloc(sizeof(struct Person)); //malloc allocates memory for the new struct, it has an arg that is the size of the struct so it knows how much memory to allocate to it

	assert(who != NULL); //make sure we actually have some real memory allocated

	who->name = strdup(name); //initialise each bit of new data for the new struct, strdup allocates a new bit of memory for the original string to be duplicated to
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who; //return the new structure
}

void Person_destroy(struct Person *who) //function called person_destroy, takes a Person struct as a parameter
{
	assert(who != NULL); //check that the struct passed as a parameter is real/ has a valid memory location

	free(who->name); //this empties/frees the memory location that this data was stored in
	free(who); //we need to do the string as we duplicated it to a different address
}

void Person_print(struct Person *who) //function called person_print, takes a Person struct as a parameter
{
	//print out each field of the passed struct
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]) //main function to run everything
{
	//make two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140); //assign the returned value, (a Person struct) from the Person_create function, to a Person struct called joe and pass the args in to make joe

	struct Person *frank = Person_create("Frank Blank", 20, 72, 180); //the same but frank instead

	//print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe); //print pointer address
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	//make everyone age 20 and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	//destroy them both to clean up

	return 0;
}