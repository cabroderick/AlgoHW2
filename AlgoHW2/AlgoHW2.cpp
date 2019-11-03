#include <iostream>

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
	printf("%d ", L(num));
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