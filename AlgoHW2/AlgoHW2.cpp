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

/*
// Counts the numbers that will reach a number
// nums: The numbers to work with
// numSize: The number of numbers to work with
// target: The number to reach
// partial: The partial array to be added
// partialSize: The size of partial
// partialIndex: The index of partial
// sumSize: The number of elements to reach the sum; 0 if any
void countNums(int* nums, int numsSize, int target, int* partial, int partialSize, int partialIndex, int sumSize) {
	int sum = 0;
	if (partialSize > sumSize) return;
	for (int i = 0; i < partialSize; i++) {
		sum += partial[i];
	}
	if (sum == target && partialSize == sumSize) { // If partial adds up to target
		for (int i = 0; i < partialSize; i++) {
			printf("%d ", partial[i]);
		}
		printf("\n");
		// print every elt of partial
	}
	if (sum >= target) {
		return;
	}

	for (int i = 0; i < numsSize; i++) {
		int n = nums[i]; // Getting elt of nums array
		int* remaining = nums + (sizeof(int) * i);
		partial[partialIndex] = n;
		countNums(remaining, numsSize - 1, target, partial, partialSize + 1, partialIndex + 1, sumSize);
	}
}

*/

void count33() {
	int square[16] = { 1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15 };
	for (int i = 0; i <= 15; i++) {
		for (int j = 1; j <= 15; j++) {
			for (int k = 2; k <= 15; k++) {
				for (int l = 3; l <= 15; l++) {
					if (square[i] + square[j] + square[k] + square[l] == 33 && ~(i & k & k & l) != 0) {
						printf("Indexes %d %d %d %d\n", i, j, k, l);
						printf("%d + %d + %d + %d = 33\n", square[i], square[j], square[k], square[l]);
						// NOT DONE
					}
				}
			}
		}
	}
}

int main() {
	int in = getInput();
	printSequence(in);
	count33();
	//countNums(nums, 5, 10, partial, 0, 0, 4);
}

