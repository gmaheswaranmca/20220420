#define SIZE 5
#include <iostream>

using namespace std;
void inputSalaries(double salary[], int length) {
	cout << "Enter salaries one by one:" << endl;
	for (int index = 0; index < length; index++) {
		cout << "Salary at index " << index << ":";
		cin >> salary[index];
	}
}

void travelSalariesF(double salary[], int length) {
	cout << "Salaries:" << endl;
	for (int index = 0; index < length; index++) {
		cout << salary[index] << " ";
	}
}

void travelSalariesFByPointerArith(double salary[], int length) {
	cout << endl << "Salaries(Pointer Arithmetic):" << endl;
	for (int index = 0; index < length; index++) {
		cout << *(salary + index) << " ";
	}
}

void travelSalariesB(double salary[], int length) {
	cout << endl << "Reverse of Salaries:" << endl;
	for (int index = length - 1; index >= 0; index--) {
		cout << salary[index] << " ";
	}
}
int main() {
	double salary[SIZE];
	//
	inputSalaries(salary, SIZE);

	travelSalariesF(salary, SIZE);

	//Pointer Arithmetic version
	travelSalariesFByPointerArith(salary, SIZE);

	travelSalariesB(salary, SIZE);

	return EXIT_SUCCESS;
}	
