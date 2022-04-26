#define MAX_ROWS 10
#define MAX_COLS 10        
#include <iostream>
using namespace std;
void inputSalaryMarix(float sal[][MAX_COLS], const int& rows, const int& cols) {
	cout << "Enter data for the salary matrix of size " << rows << "x" << cols << endl;
	for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
		for (int colIndex = 0; colIndex < cols; colIndex++) {
			cout << "Element at row " << rowIndex << " and col at " << colIndex << ":";
			cin >> sal[rowIndex][colIndex];
		}
	}
}
void printSalaryMatrix(float sal[][MAX_COLS], const int& rows, const int& cols) {
	cout << "The salary matrix:" << endl;
	for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
		for (int colIndex = 0; colIndex < cols; colIndex++) {
			cout << sal[rowIndex][colIndex] << " ";
		}
		cout << endl;
	}
}

int main() {
	float salaryMatrix[MAX_ROWS][MAX_COLS];
	int rowCount = 3, colCount = 5;
	cout << "Enter rows count:";
	cin >> rowCount;

	cout << "Enter columns count:";
	cin >> colCount;

	inputSalaryMarix(salaryMatrix, rowCount, colCount);

	printSalaryMatrix(salaryMatrix, rowCount, colCount);

	return 0;
}
