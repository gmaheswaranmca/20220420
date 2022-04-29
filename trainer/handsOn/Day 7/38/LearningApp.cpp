/*4. Find number of prime numbers in an array.
Extended Qn Statement:
o Declare c++ dynamic array for N 
o Read N numbers from keyboard using the function 
    void readNumbers(int *numbers, int size)
o Define the function to count number of fibonacci numbers in the array     
    int countPrime(int *numbers, int size)
  and print in the console 
o Define int isPrime(int &num)  returns 1 if prime otherwise 0
  
Use: pointer arithmetic or pointer expression. Dont use subscript operator.  
--------------------------------------------------------------
*/
#include<iostream>
using namespace std;
void readNumbers(int* numbers, int size) {
	cout << "Enter numbers one by one:" << endl;
	for (int I = 0; I < size; I++) {
		cout << "Number at " << I << ":";
		cin >> (*(numbers+I));
	}
}
int isPrime(int& num) {
	int flag = 1;
	if (num == 1) {
		flag = 0;
	}
	else{
		for (int I = 2; I < num/2; I++) {
			if (num % I == 0) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
int countPrime(int* numbers, int size) {
	int count = 0;
	for (int I = 0; I < size; I++) {
		if (isPrime((*(numbers + I))) == 1) {
			count++;
		}
	}
	return count;
}

int main() {
	int N;
	cout << "number of the numbers:";
	cin >> N;

	int* A = new int[N]; // dynamic array of size "N"

	readNumbers(A, N);
	int count = countPrime(A, N);

	cout << "Prime Numbers in the given array is " << count << endl;

	delete[] A;

	return EXIT_SUCCESS;
}