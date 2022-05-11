#include"EmployeeApplication.h"
#include"CustomerApplication.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{	
	cout << "********************************************" << endl;
	std::cout << "Finance Application!\n";
	cout << "********************************************" << endl;
	int menu;
	do{
		cout << "1. Customer Application" << endl;
		cout << "2. Employee Application" << endl;
		cout << "Your Option:"; cin >> menu;
		if (1 == menu) {
			CustomerApplication::customerApp();
		}
		else if (2 == menu) {
			EmployeeApplication::empLogin();
		}
	} while (menu != 0);

	return EXIT_SUCCESS;
}
