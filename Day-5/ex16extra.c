/* 
For this the extra task was to create a structure 'on the stack'
instead of using pointers. I did a bit of research on ubuntuforums.org
and tutorialspoint to get the idea. Personally I prefer this way than
on the heap as it's more familiar to the Java and OOP programming
I've done previously.
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person Create(char *name, int age, int height, int weight) {
	struct Person person;
	person.name = strdup(name);
	person.age = age;
	person.height = height;
	person.weight = weight;
	return person;
}

int main (void) {
	struct Person Casey = Create("Casey Williams", 15, 72, 140);
	printf("Hi, my name is %s and I am %d years old. I am %d inches tall and weigh %d pounds.\n", Casey.name, Casey.age, Casey.height, Casey.weight);
	free(Casey.name);
	return 0;
}