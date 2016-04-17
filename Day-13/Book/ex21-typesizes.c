//this part of exercise 21 is about the stdint header and type sizes
//stdint.h defines both a set of typedefs for exactsized integers and 
//also a set of macros for the sizes of all types.

#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	//this goes in the form (u)int(BITS)_t

	//is an 8 bit signed integer
	int8_t bytey;

	//is an 8 bit unsigned integer
	uint8_t unbytey;

	//these are the macros in stdint.h that return the max and min
	//values for the type sizes, its a similar format as before
	printf("%d\n", INT8_MAX);
	printf("%d\n", INT8_MIN);
	printf("%d\n", UINT8_MAX);

	return 0;
}

/*
There are also macros in stdint.h for sizes of the size_t type, i
ntegers large enough to hold pointers, and other handy size defining 
macros. Compilers have to at least have these, and then they can allow
other larger types.

Here is a full list should be in stdint.h:

int_least(N)_t
holds at least (N) bits.

uint_least(N)_t
holds at least (N) bits unsigned.

INT_LEAST(N)_MAX
max value of the matching least (N) type.

INT_LEAST(N)_MIN
min value of the matching least (N) type.

UINT_LEAST(N)_MAX
unsigned maximum of the matching (N) type.

int_fast(N)_t
similar to int_least*N*_t but asking for the "fastest" with at least that precision.

uint_fast(N)_t
unsigned fastest least integer.

INT_FAST(N)_MAX
max value of the matching fastest (N) type.

INT_FAST(N)_MIN
min value of the matching fastest (N) type.

UINT_FAST(N)_MAX
unsigned max value of the matching fastest (N) type.

intptr_t
a signed integer large enough to hold a pointer.

uintptr_t
an unsigned integer large enough to hold a pointer.

INTPTR_MAX
max value of a intptr_t.

INTPTR_MIN
min value of a intptr_t.

UINTPTR_MAX
unsigned max value of a uintptr_t.

intmax_t
biggest number possible on that system.

uintmax_t
biggest unsigned number possible.

INTMAX_MAX
largest value for the biggest signed number.

INTMAX_MIN
smallest value for the biggest signed number.

UINTMAX_MAX
largest value for the biggest unsigned number.

PTRDIFF_MIN
minimum value of ptrdiff_t.

PTRDIFF_MAX
maximum value of ptrdiff_t.

SIZE_MAX
maximum of a size_t.

*/