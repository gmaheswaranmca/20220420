/*
Read MxN int matrix 
and find sum of numbers of each row 

Example:

10 20 30 40 50                   => 150
60 70 80 90 12                   => 312
14 16 18 22 24  3 x 5 matrix     => 94

Data for the program:
3 5
10 20 30 40 50
60 70 80 90 12
*/
#define MAX_ROWS 10
#define MAX_COLS 10
#include<iostream>

using namespace std;

void readMatrx(int mat[][MAX_COLS],const int& rows, const int& cols) {
	cout << "Enter the matrix:" << endl;
	for (int I = 0; I < rows; I++) {
		for (int J = 0; J < cols; J++) {
			cout << "Enter the element at row " << I << " at col " << J << ":";
			cin >> mat[I][J];
		}
	}
}
int findArraySum(int ar[], const int& size) {
	int s = 0;
	for (int K = 0; K < size; K++) {
		s = s + ar[K];
	}
	return s;
}

void findSumOfEachRow(int mat[][MAX_COLS], const int& rows, const int& cols, int sumAr[]) {
	long sum = 0L;
	for (int I = 0; I < rows; I++) {
		sumAr[I] = findArraySum(mat[I], cols);
	}
}

int main() {
	int M, N;
	int matrix[MAX_ROWS][MAX_COLS], sumOfRow[MAX_ROWS];
	cout << "Enter size of the matrix(MxN) space separated:";
	cin >> M >> N;

	readMatrx(matrix, M, N);

	findSumOfEachRow(matrix, M, N, sumOfRow);

	cout << "Sum of the rows:" << endl;
	for (int L = 0; L < M; L++) {
		cout << sumOfRow[L] << " ";
	}

	return EXIT_SUCCESS;
}
