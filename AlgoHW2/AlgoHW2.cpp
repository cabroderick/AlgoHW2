#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

double previousTime = 1;

/*
Collin Broderick, Praise Eteng, Siddhant Banerjee
Homework questions:
1.
The characteristic equation is -1 + 3(3^n)
The reccurence's order of growth is O(b^n)
2.
Lucas is also known for the tower of Hanoi
3.
The ratio of successive calculations is the golden ratio (~1.6)
The order of growth is O(n^2)
4.
The sum with the greatest number of combinations is 66, which appeared 1364 times. That sum is the halfway to the maximum value that can be created with the values of the square.
*/


// Gets the user input
int getInput() {
	printf("Enter a number for a Lucas sequence: ");
	int in;
	scanf_s("%d", &in);
	printf("\n");
	return in;
}

// Calculates the value of the sequence at position n
// n: The position in the Lucas sequence
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
// num: The number to be printed
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

// Prints all the four-number combos that add to 33
void count33() {
	int square[16] = { 1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15 };
	for (int i = 0; i <= 15; i++) {
		for (int j = 1; j <= 15; j++) {
			for (int k = 2; k <= 15; k++) {
				for (int l = 3; l <= 15; l++) {
					if (square[i] + square[j] + square[k] + square[l] == 33 && (i!=j && i != k && i != l && j != k && j != l && k != l)) {
						//printf("Indexes %d %d %d %d\n", i, j, k, l);
						printf("%d + %d + %d + %d = 33\n", square[i], square[j], square[k], square[l]);
					}
				}
			}
		}
	}
}

// Finds all combinations for a list numbers
void findCombos() {
	int nums[16] = { 1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15 };
	int maxCombo = 0;
	int maxSum = 0;
	int results[133]; // Each index in results indicates a possible sum, and the value at that index indicates how many times that sum was achieved
	for (int i = 0; i < 133; i++) { // Fills results with 0s
		results[i] = 0;
	}
	// Generates all 16-digit binary permutations
	for (int i = 0; i <= 65535; i++) {
		int total = 0;
		int a = i; // Duplicat of i to be shifted
		for (int j = 0; j < 16; j++) {
			int include = a & 1;
			if (include) {
				total += nums[j];
			}
			a = a >> 1;
		}
		results[total]++; // Indexes the total at array value total, which will indicate that that sum was reached one more time
		if (results[total] > maxCombo) {
			maxCombo = results[total];
			maxSum = total;
		}
	}
	for (int i = 0; i < 133; i++) { // Indexes through results
		if (results[i] > 0) { // If the given sum appeared at least once
			printf("%d appeared %d times\n", i, results[i]);
		}
	}
	printf("The greatest number of cominbations was %d, which summed to %d.\n", maxCombo, maxSum);
}

int main() {
	int in = getInput();
	printSequence(in);
	count33();
	findCombos();
}