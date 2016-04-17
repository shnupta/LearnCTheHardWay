// type conversion is changing the type of data in expressions
/*
C uses a sort of "stepped type promotion" mechanism, 
where it looks at two operands on either side of an expression, 
and promotes the smaller side to match the larger side before doing 
the operation. If one side of an expression is on this list, 
then the other side is converted to that type before the operation 
is done, and this goes in this order:

long double
double
float
int (but only char and short int);
long
*/

//it's probably a ot easier to cast the operands themselves

#include <stdio.h>

int main(int argc, char const *argv[])
{
	long along = 12367456754;
	char initial = 'C';
	int age = 15;
	double subtractor = 12.123456;

	//without casting:
	double sum = along + initial - age * subtractor;

	printf("Without casting: %f\n\n", sum);

	//rather than try and figure out if it will cast itself to a double,
	//just do it ourselves
	double newSum = (double)along + (double)initial - (double)age * subtractor;

	printf("With casting: %f\n\n", newSum);

	return 0;
}

