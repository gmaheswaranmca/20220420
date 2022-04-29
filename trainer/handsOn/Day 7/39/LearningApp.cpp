/*
//Create emp_t of struct {empId, empName, sal, bonus}
//C++ dynamic memory for emp_t 
//Read emp details using function void readEmp(emp_t *empAddr)
//find total salary using function 
// float findTotalSalary(emp_t *empAddr) 
//and print the total salary 
--------------------------------------------------------------
*/
#include<iostream>
using namespace std;

struct _emp_t {
	int empId;
	char empName[256];
	float sal;
	float bonus;
};
typedef struct _emp_t emp_t;

void readEmp(emp_t* empAddr) {
	cout << "Employee ID:";
	cin >> (*empAddr).empId;

	cout << "Employee Name:";
	cin >> (*empAddr).empName;

	cout << "Salary:";
	cin >> (*empAddr).sal;

	cout << "Bonus:";
	cin >> (*empAddr).bonus;
}
float findTotalSalary(emp_t* empAddr) {
	float tot = empAddr->sal + empAddr->bonus;
	return tot;
}


int main() {
	emp_t* empPtr = new emp_t;

	readEmp(empPtr);
	float totSal = findTotalSalary(empPtr);

	cout << "Total salary is " << totSal << endl;

	delete empPtr;
	empPtr = NULL;

	return EXIT_SUCCESS;
}
--------------------------------------------------------------