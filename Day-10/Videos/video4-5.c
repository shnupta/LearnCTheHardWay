#include <stdio.h>
#include <stdlib.h>

//Passing strings to functions as pointers

void editMessageSent(char * message, int size) {
	char newMessage[] = "New messasge";

	if(size > sizeof*(newMessage)) {
		for(int i = 0; i < sizeof(newMessage); i++) {
			message[i] = newMessage[i];
		}
	} else {
		printf("New message is too big\n\n");
	}
}

void main() {
	char randomMessage[] = "Edit my message.";

	printf("Old message: %s\n\n", randomMessage);

	editMessageSent(randomMessage, sizeof(randomMessage));

	printf("New Message: %s\n\n", randomMessage);
}

//finished video 4! :D