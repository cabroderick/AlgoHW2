#include <iostream>
#include <time.h>

double previousTime = 1;

// Gets the user input
int getInput() {
	printf("Enter a number for a Lucas sequence: ");
	int in;
	scanf_s("%d", &in);
	printf("\n");
	return in;
}

// Calculates the value of the sequence at position num
int L(int n) {
	switch (n) {
	case(0):
		return 2;
		break;
	case(1):
		return 1;
		break;
	default:
		// Code for sequence
		return L(n - 1) + L(n - 2);
		break;
	}
}

// Prints a number num in the Lucas sequence
void printNum(int num) {
	double startTime = clock();
	int l = L(num);
	double endTime = clock();
	double timeElapsed = (endTime - startTime) / CLOCKS_PER_SEC;
	printf("L(%d) = %d\nFound in %f seconds\n",num, l, timeElapsed);
	double ratio = timeElapsed / previousTime;
	if (num > 0) {
		printf("Time(L(%d))/Time(L(%d)) = %f\n", num, num - 1, ratio);
	}
	previousTime = timeElapsed;
}

// Prints the Lucas numbers
// num: Number of sequence elements
void printSequence(int num) {
	for (int i = 0; i < num; i++) {
		printNum(i);
	}
}

int main() {
	int in = getInput();
	printSequence(in);
}