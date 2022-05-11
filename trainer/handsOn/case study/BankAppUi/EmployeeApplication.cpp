#include "EmployeeApplication.h"
#include <iostream>
#include <string>
using namespace std;
void EmployeeApplication::empApp() {
	int menu;
	do {
		cout << "1. Loan Processing" << endl;
		cout << "2. Dashboard" << endl;
		cout << "3. Reports(Daily/Monthly/Date Range/Scheme Wise)" << endl;
		cout << "Your Option:"; cin >> menu;
		if (1 == menu) {
			cout << "Loan Processing." << endl;
		}
		else if (2 == menu) {
			cout << "Dashboard." << endl;
		}
		else if (3 == menu) {
			cout << "Reports." << endl;
		}
	} while (menu != 0);
}
void EmployeeApplication::empLogin() {
	string data;
	cout << "Enter User Name:"; cin >> data;
	cout << "Enter Password:"; cin >> data;
	cout << "!!!You have successfully logged in:" << endl << endl;
	empApp();
}