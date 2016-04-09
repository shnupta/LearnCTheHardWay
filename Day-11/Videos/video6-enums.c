// I'm using this video to learn about enums as I haven't yet learn them

//you should use enums when you know you'll never ever need anything 
//but the values that go inside of here.

//link: https://youtu.be/MjQ6PEQen-Q

// The video also explains structs (better in video 5), unions and more

#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	//Enumerated Type!!!
	typedef enum {
		INDIV, OUNCE, POUND
	} quantity;
	//a typedef allows you to effectively create your own data type
	// IMPORTANT: a union can only hold 1 value at a time,
	// this is because the values are stored in the same memory location
	typedef union {
		short individual;
		float pound;
		float ounce;
	} amount; //amount is now the name of this 'data type' you've created

	typedef struct {
			char *brand;
			amount theAmount;
			quantity theQuantity;
	} orangeProduct;


	amount orangeAmount = {.ounce = 16}; //designated initiaser
	
	//also you can do this
	//amount orangeAmount.individual = 4;

	/*
	orangeAmount.individual = 4;

	//THIS ISN'T RIGHT
	printf("Orange juice amount: %.2f : Size %d\n\n", 
		orangeAmount.ounce, sizeof(orangeAmount.ounce));

	printf("Number of oranges: %d : Size: %d\n\n", 
		orangeAmount.individual, sizeof(orangeAmount.individual));
	*/


	orangeProduct productOrdered = {"Chiquita", .theAmount.ounce = 16};

	printf("You bought %.2f ounces of %s oranges.\n\n",
		productOrdered.theAmount.ounce, productOrdered.brand);


	quantity quantityType = INDIV;

	orangeAmount.individual = 4;

	if(quantityType == INDIV) {
		printf("You bought %d oranges\n\n", orangeAmount.individual);
	} else if(quantityType == OUNCE) {
		printf("You bought %.2f ounces of oranges\n\n", orangeAmount.ounce);
	} else {
		printf("You bought %.2f pounds of oranges\n\n", orangeAmount.pound);
	}



	return 0;
}