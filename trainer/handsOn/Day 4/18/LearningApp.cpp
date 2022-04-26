/*
1. Read N long numbers from console 
   and find sum of odd numbers in the list 
*/
#define MAX_SIZE 1000
#include<iostream>

using namespace std;


void readNumbers(long numList[], const int &count) {
	cout << "Enter large numbers one by one:" << endl;
	for (int index = 0; index < count; index++) {
		cout << "Enter number at index " << index << ":";
		cin >> numList[index];
	}
}

long findSumOfOdd(long numList[], const int& count) {
	long sum = 0L;
	for (int index = 0; index < count; index++) {
		if (numList[index] % 2 != 0) {
			sum = sum + numList[index];
		}
	}
	return sum;
}

int main() {
	int numCount;
	cout << "Enter number of numbers:";
	cin >> numCount; 
	
	long numbers[MAX_SIZE];
	readNumbers(numbers, numCount);
	long sumOfNums = findSumOfOdd(numbers, numCount);

	cout << "Sum of Odd Numbers is " << sumOfNums << endl;

	return EXIT_SUCCESS;
}

/*
Data:
3
11 20 13
*/