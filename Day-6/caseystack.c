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

//create the stack structure and state the members of the struct
struct CaseyStack {
	int MAX_SIZE;
	int top;
	int data[];
};

struct CaseyStack *CreateStack (int MAX_SIZE)
{
	//allocate some memory space
	struct CaseyStack *stack = malloc(sizeof(struct CaseyStack));

	//check we have valid memory
	assert(stack != NULL);

	//initialise the member values
	stack->MAX_SIZE = MAX_SIZE;
	stack->top = -1;
	stack->data[MAX_SIZE];

	return stack;
}

//explicitly declare the functions
void push(struct CaseyStack *stack, int data);
void pop(struct CaseyStack *stack);
int peek(struct CaseyStack *stack);
int isFull(struct CaseyStack *stack);
int isEmpty(struct CaseyStack *stack);
int getSize(struct CaseyStack *stack);


void push(struct CaseyStack *stack, int data)
{
	//if its full we cant add so check
	if(!isFull(stack)) {
		//if not increase the top value and assign that index in the data array to the value of the passed arg
		stack->top += 1;
		stack->data[stack->top] = data;
	} else {
		printf("Stack is full.");
	}
}

void pop(struct CaseyStack *stack)
{
	//if its not empty, as if it is we cant remove anything
	if(!isEmpty(stack)) {
		//decrement the top value
		stack->top -= 1;
	} else {
		printf("Stack is empty.");
	}
}

int peek(struct CaseyStack *stack)
{
	//return the data at the top index
	return stack->data[stack->top];
}

int isFull(struct CaseyStack *stack)
{
	//if the top number is the same as the max size its full
	if(stack->top == stack->MAX_SIZE) {
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(struct CaseyStack *stack)
{
	//if below 0 (first index) its empty
	if(stack->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

//thought i'd implement my own function to see the size of the stack
int getSize(struct CaseyStack *stack)
{
	//if its not empty and also not full, return the size
	if(!isEmpty(stack) && !isFull(stack)) {
		return stack->top + 1;
	} else {
		printf("Stack is out of bounds.");
		return -1;
	}
}


int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("You need to initialise the stack size.\n");
		exit(1);
	}
	int size = atoi(argv[1]);
	struct CaseyStack *casey = CreateStack(size);
	push(casey, 15);
	push(casey, 16);
	pop(casey);
	int topel = peek(casey);
	int sizekc = getSize(casey);
	printf("top element is: %d\n", topel);
	printf("the size is: %d\n", sizekc);
	printf("Is the stack empty: %d\n", isEmpty(casey));

	return 0;

}





