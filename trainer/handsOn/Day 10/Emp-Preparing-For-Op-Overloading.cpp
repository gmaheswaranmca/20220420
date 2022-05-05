#include<iostream>
#include<string>
using namespace std;
class Emp {
private:
	string empName;
	float salary;
	float bonus;
	float netSalary;
public:
	Emp();
	void read();// >>
	void print();//<<
	void updateNetSalary();
	float getNetSalary();
	friend Emp findSum(Emp& firstEmp, Emp& secondEmp); //+
};

Emp::Emp() {
	this->empName = "";
	this->salary = 0.0f;
	this->bonus = 0.0f;
	this->netSalary = 0.0f;
}
void Emp::read() {
	cout << endl << endl;
	cout << "Emp Name:"; cin >> this->empName;
	cout << "Salary:"; cin >> this->salary;
	cout << "Bonus:"; cin >> this->bonus;
}
void Emp::print() {
	cout << endl << endl;
	cout << "Emp Name:" << this->empName << endl;
	cout << "Salary:" << this->salary << endl;
	cout << "Bonus:" << this->bonus << endl;
	cout << "Net Salary:" << this->netSalary << endl;
}
void Emp::updateNetSalary() {
	this->netSalary = this->salary + this->bonus;
}
float Emp::getNetSalary() {
	return this->netSalary;
}

Emp findSum(Emp& firstEmp, Emp& secondEmp) {
	Emp sumEmp;
	//float sum = firstEmp.netSalary + secondEmp.netSalary;
	sumEmp.netSalary = firstEmp.netSalary + secondEmp.netSalary;
	return sumEmp;
}


int main() {
	Emp uday;
	uday.read();

	Emp anil;
	anil.read();

	uday.updateNetSalary();
	anil.updateNetSalary();

	uday.print();
	anil.print();

	Emp sumEmp = findSum(uday, anil);
	cout << endl << endl << "Sum of salaries is " << sumEmp.getNetSalary() << endl;

	return EXIT_SUCCESS;
}
