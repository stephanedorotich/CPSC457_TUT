// My first C++ Program

#include <iostream>

int main(int argc, char ** argv) {
	printf("Number of arguments: %d\n",argc);
	int i = 0;
	while (i < argc) {
		printf("Argument %d: %s\n",i,argv[i]);
		i++;
	}
	return 0;
}
