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
	
	friend ostream& operator<<(ostream& out, const Emp& firstEmp);
	void updateNetSalary();
	
	float getNetSalary();
	Emp operator+(const Emp& secondEmp);
	Emp operator++();//pre increment
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
Emp Emp::operator++() {//50
	//++a -> a = a + 1; return a;
	Emp& firstEmp = (*this);
	Emp res = firstEmp;
	firstEmp.netSalary += 50;
	return res;
}

ostream& operator<<(ostream& output, const Emp& firstEmp) {
	output << firstEmp.empName << "[" << firstEmp.salary << ","
		<< firstEmp.bonus << "," << firstEmp.netSalary << "]" << endl;
	return output;
}

int main() {
	Emp uday("Uday",7000.0f,10.0f);
	Emp anil("Anil", 6500.0f, 100.0f);
	Emp shrikant("Shrikant", 5500.0f, 700.0f);
	Emp divya("Divya", 6000.0f, 300.0f);//25000,1110=26110

	
	cout << uday << anil << shrikant << divya;
	//cout.operator<<(cout.operator<<(cout.operator<<(cout.operator<<(cout,uday),anil),shrikant),divya);

	Emp res = ++uday;
	
	cout << uday;
	//cout.operator<<(cout,uday);

	Emp sumEmp = (((uday + anil) + shrikant) + divya);
	//uday.operator+(anil).operator+(shrikant).opeartor+(divya);
	//uday.operator+(anil)	//uday + anil -> Emp obj
	cout << endl << endl << "Sum of salaries is " << sumEmp.getNetSalary() << endl;

	return EXIT_SUCCESS;
}
