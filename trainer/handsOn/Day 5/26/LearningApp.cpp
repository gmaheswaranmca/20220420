//To extract each attribute of employee record in csv (comma separated value)
//and assign into emp structure object
//Example:
//101,Maheswaran,Trainer,200.20
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct _emp_t {
	int empId;
	char empName[256];
	char jobTitle[256];
	float sal;
};
typedef struct _emp_t emp_t;
int main() {
	emp_t mahesh;
	char csv[] = "101,Maheswaran,Trainer,200.20";
	char* attr;
	cout << "The csv text:";
	cout << csv << endl;

	attr = strtok(csv, ","); // "101"
	mahesh.empId = atoi(attr);
	attr = strtok(NULL, ","); // "Maheswaran"
	strcpy(mahesh.empName, attr);
	attr = strtok(NULL, ","); // "Trainer"
	strcpy(mahesh.jobTitle, attr);
	attr = strtok(NULL, ","); // "200.20"
	mahesh.sal = atof(attr);

	cout << "empId:" << mahesh.empId << endl;
	cout << "empName:" << mahesh.empName << endl;
	cout << "jobTitle:" << mahesh.jobTitle << endl;
	cout << "sal:" << mahesh.sal << endl;

	return EXIT_SUCCESS;
}