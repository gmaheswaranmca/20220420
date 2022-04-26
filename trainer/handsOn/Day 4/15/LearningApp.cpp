#define SIZE 5
#include <iostream>

using namespace std;
void inputSalaries(double salary[], int length, int index) {
	if (index < length) {
		cout << "Salary at index " << index << ":";
		cin >> salary[index];
		inputSalaries(salary, length, index + 1);
	}
}

void travelSalariesF(double salary[], int length, int index) {
	if (index < length) {
		cout << salary[index] << " ";
		travelSalariesF(salary, length, index + 1);
	}
}

void travelSalariesFByPointerArith(double salary[], int length, int index) {
	if (index < length) {
		cout << *(salary + index) << " ";
		travelSalariesFByPointerArith(salary, length, index + 1);
	}
}

void travelSalariesB(double salary[], int length, int index) {
	if (index < length) {
		travelSalariesB(salary, length, index + 1);
		cout << salary[index] << " ";
	}
}
int main() {
	double salary[SIZE];
	//
	cout << "Enter salaries one by one:" << endl;
	inputSalaries(salary, SIZE, 0);

	cout << "Salaries:" << endl;
	travelSalariesF(salary, SIZE, 0);

	//Pointer Arithmetic version
	cout << endl << "Salaries(Pointer Arithmetic):" << endl;
	travelSalariesFByPointerArith(salary, SIZE, 0);

	cout << endl << "Reverse of Salaries:" << endl;
	travelSalariesB(salary, SIZE, 0);

	return EXIT_SUCCESS;
}
