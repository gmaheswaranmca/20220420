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
	friend Emp operator+(const Emp& firstEmp, const Emp& secondEmp);
	friend Emp operator++(Emp& firstEmp);
	friend Emp operator++(Emp& firstEmp,int);
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

Emp operator+(const Emp& firstEmp,const Emp& secondEmp) {
	Emp sumEmp;
	//sumEmp.netSalary = this->netSalary + secondEmp.netSalary;
	sumEmp.netSalary = firstEmp.netSalary + secondEmp.netSalary;
	return sumEmp;
}
Emp operator++(Emp& firstEmp) {//pre increment
	//b=++a; a = a + 1; b = a;
	firstEmp.netSalary += 50;

	Emp res = firstEmp;
	return res;
}
Emp operator++(Emp& firstEmp, int) {//post increment
	//b=a++; b = a; a = a + 1;
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

	Emp res = ++uday; //operator++(uday);
	Emp anoRes = anil++;//operator++(anil,0);
	
	cout << uday;
	cout << anil;
	//cout.operator<<(cout,uday);

	Emp sumEmp = (((uday + anil) + shrikant) + divya);
	//opeartor+(operator+(operator+(uday,anil),shrikant),divya);
	
	cout << endl << endl << "Sum of salaries is " << sumEmp.getNetSalary() << endl;

	return EXIT_SUCCESS;
}
