#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	printf("Hello World!\n");

	// Changes by William Dam
	// Yes, let's print Hello World 25x
	for (int i = 0; i < 25; i++) {
		printf("Hello World!\n");
	}

	printf("\nHi I'm Tinron\n\n");

	//random number of hello worlds
	srand (time(NULL));
	int a = rand() % 100 + 1; //random from 1-100

	for (int i = 0; i < a; i++) {
		printf("Hello World! - %i/%i\n", (i + 1), a);
	}

	return 0;
}
