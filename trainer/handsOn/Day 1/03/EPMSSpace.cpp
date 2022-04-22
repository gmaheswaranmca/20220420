#include<iostream>
#include "EPMSSpace.h"
namespace EPMSSpace{
	char empName[255];
	int empCode;
	PayRoll_t payRoll;
	void readEmp(void)
	{
		using std::cout;
		using std::cin;
		std::cout << "Enter Employee Name:";
		std::cin >> empName;

		std::cout << "Enter Employee Code:";
		std::cin >> empCode;

		std::cout << "Enter Basic Salary:";
		std::cin >> payRoll.basic;

		std::cout << "Enter Bonus:";
		std::cin >> payRoll.bonus;
	}

	void printEmp(void)
	{
		std::cout << "Employee Name:" << empName << std::endl;
		std::cout << "Employee Code:" << empCode << std::endl;
		std::cout << "Basic Salary:" << payRoll.basic << std::endl;
		std::cout << "Bonus:" << payRoll.bonus << std::endl;
	}
}