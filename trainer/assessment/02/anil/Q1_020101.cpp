Duration: 30 minutes
Score: 30 marks
Q1:
Given N employees of attributes{empId,salary}, 
Find sum of salaries of all employees.

Note: Define dynamic array for the employee structure
Here, you have to define a function to calculate Salaries Sum
	float findSalariesSum(employee_t empList[],int& empCount);
Where, employee_t typedef name for the 
	struct _employee_t{int empId; float salary;};
    
Initial Code:
#include<iostream>
using namespace std;
struct _employee_t{int empId; float salary;};
typedef struct _employee_t	employee_t;
float findSalariesSum(employee_t empList[],int& empCount){
	/* CODE HERE: to find Salaries Sum of empList and return the Sum */
}
int main(){
	int N;
	cout << "Enter number of employees:";
	cin >> N;
	employee_t* employees = /*CODE HERE:C++ Dynamic Array of size N*/;
	for(int I = 0; I < N; I++){
		cout << "Employee at " << I << ":" << endl;
		cout << "Employee ID:"; cin >> employees[I].empId;
		cout << "Salary:"; cin >> employees[I].salary;
	}
    float sum = findSalariesSum(employees,N);
	cout << "Sum of salaries of all employees is " << sum << endl;
	/*CODE HERE:Free C++ Dynamic Array*/
	employees = NULL;
	return EXIT_SUCCESS;
}
Test Case:
Enter number of employees:2
Employee at 0:
Employee ID:1
Salary:100
Employee at 1:
Employee ID:2
Salary:50
Sum of salaries of all employees is 150

