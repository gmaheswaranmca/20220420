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
	Emp(string empName, float salary, float bonus);
	void print();
	void updateNetSalary();
	
	float getNetSalary();
	Emp operator+(const Emp& secondEmp);
};
Emp::Emp() {
	Emp("",0.0f,0.0f);
}
Emp::Emp(string empName, float salary, float bonus) {
	this->empName = empName;
	this->salary = salary;
	this->bonus = bonus;
	//this->netSalary = 0.0f;
	this->updateNetSalary();
}
void Emp::print() {
	cout << this->empName << "[" << this->salary << "," 
		<< this->bonus << "," << this->netSalary << "]" << endl;
}
void Emp::updateNetSalary() {
	this->netSalary = this->salary + this->bonus;
}
float Emp::getNetSalary() {
	return this->netSalary;
}

Emp Emp::operator+(const Emp& secondEmp) {
	const Emp& firstEmp = (*this);
	Emp sumEmp;
	//sumEmp.netSalary = this->netSalary + secondEmp.netSalary;
	sumEmp.netSalary = firstEmp.netSalary + secondEmp.netSalary;
	return sumEmp;
}

int main() {
	Emp uday("Uday",7000.0f,10.0f);
	Emp anil("Anil", 6500.0f, 100.0f);
	Emp shrikant("Shrikant", 5500.0f, 700.0f);
	Emp divya("Divya", 6000.0f, 300.0f);//25000,1110=26110

	uday.print(); anil.print(); shrikant.print(); divya.print();

	Emp sumEmp = (((uday + anil) + shrikant) + divya);
	//uday.operator+(anil).operator+(shrikant).opeartor+(divya);
	//uday.operator+(anil)	//uday + anil -> Emp obj
	cout << endl << endl << "Sum of salaries is " << sumEmp.getNetSalary() << endl;

	return EXIT_SUCCESS;
}
