#include <stdio.h>
#include "dbg.h"
#include <ctype.h>

int print_a_message(const char *msg)
{
	printf("A STRING: %s\n", msg);

	return 0;
}

int uppercase(const char *msg, int msg_length) {
	check(msg_length == strlen(msg), "Length is not the same as the length of provided string.");

	int i = 0;

	for(i = 0; i < msg_length; i++) {
		printf("%c", toupper(msg[i]));
	}

	printf("\n");

	return 0;

error:
	return -1;
}

int lowercase(const char *msg, int msg_length) {
	check(msg_length == strlen(msg), "Length is not the same as the length of provided string.");

	int i = 0;
	
	for(i = 0; i < msg_length; i++) {
		printf("%c", tolower(msg[i]));
	}

	printf("\n");

	return 0;

error:
	return -1;
}

int fail_on_purpose(const char *msg) {
	return -1;
}