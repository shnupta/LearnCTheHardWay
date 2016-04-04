/*
So this is my go at creating a stack data structure from scratch in C.
It was one of the extra credit tasks I could choose to do from ex17.
I'm using www.tutorialspoint.com/data_structures_alorithms/stack_algorithm
to get the idea of the basic functions I should implement.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct CaseyStack {
	int MAX_SIZE;
	int top;
};

struct CaseyStack *CreateStack (int MAX_SIZE, int top)
{
	struct CaseyStack *stack = malloc(sizeof(struct CaseyStack));

	assert(stack != NULL);

	stack->MAX_SIZE = MAX_SIZE;
	stack->top = top;

	return stack;
}


void push(struct CaseyStack *stack)
{
	//TODO
}

void pop(struct CaseyStack *stack)
{
	//TODO
}

int peek(struct CaseyStack *stack)
{
	//TODO	
	return 1;
}

int isFull(struct CaseyStack *stack)
{
	//TODO
	return 1;
}

int isEmpty(struct CaseyStack *stack)
{
	//TODO
	return 1;
}



int main(int argc, char *argv[])
{
	struct CaseyStack *casey = CreateStack(8, 2);
	printf("%d\n", casey->top);
}





