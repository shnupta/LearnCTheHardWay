#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i = 0;

	while(i < 1000) {
		usleep(3000);
	}
	
	return 0;
}