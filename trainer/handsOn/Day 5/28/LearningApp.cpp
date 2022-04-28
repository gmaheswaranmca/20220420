/*
Gate keeper log application
Sample Logs 
3:30PM teacher Name:Manikanda
3:35PM student 1030					Anil
3:40PM student 4012					Shrikant
4:00PM parent 3456 7898 7323   		Maheswaran

Avinash is the programmer 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

union persons_t {
	char teacherName[256];
	int studentRollNum;
	long long parentAadhaar;
};					 
struct log_t {
	char time[10];
	int personType; //1-teacher, 2-student, 3-parent
	union persons_t person;
};

void readLog(struct log_t& entry) {
	cout << "Enter Log:" << endl;
	
	cout << "Time:";
	cin >> entry.time;

	cout << "Person(1-Teacher,2-Student,3-Parent):";
	cin >> entry.personType;

	switch (entry.personType) {
	case 1:
		cout << "Teacher Name:";
		cin >> entry.person.teacherName;
		break;
	case 2:
		cout << "Student Roll Number:";
		cin >> entry.person.studentRollNum;
		break;
	case 3:
		cout << "Parent aadhaar number:";
		cin >> entry.person.parentAadhaar;
		break;
	}
}

void printLog(struct log_t& entry) {
	cout << "Gate keeper a log entry:" << endl;

	cout << "Time:" << entry.time << endl;
	
	switch (entry.personType) {
	case 1:
		cout << "Teacher Name:" << entry.person.teacherName << endl;
		break;
	case 2:
		cout << "Student Roll Number:" << entry.person.studentRollNum << endl;
		break;
	case 3:
		cout << "Parent aadhaar number:" << entry.person.parentAadhaar << endl;
		break;
	}
}
int main() {
	struct log_t log;

	readLog(log);
	printLog(log);

	return EXIT_SUCCESS;
}