//Union Example
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct emp_st {
	int empId;
	char empName[256];
	float salaray;
};

union emp_ut {
	int empId;			//4
	char empName[256];	//256
	float salaray;		//4
};
int main() {
	struct emp_st empS;
	empS.empId = 101;
	strcpy(empS.empName, "Mahesh");
	empS.salaray = 2000;

	cout << "Employee Struct object:" << endl;
	cout << "ID:" << empS.empId << endl;
	cout << "Name:" << empS.empName << endl;
	cout << "Salary:" << empS.salaray << endl;

	union emp_ut empU;	
	empU.empId = 101;
	empU.salaray = 2000;
	strcpy(empU.empName, "Mahesh");
	
	cout << "Employee Union object:" << endl;
	cout << "ID:" << empU.empId << endl;
	cout << "Name:" << empU.empName << endl;
	cout << "Salary:" << empU.salaray << endl;

	return EXIT_SUCCESS;
}