--------------------------------------------------------
Q. 1
Find the output

#include<iostream>
#include<string>
using namespace std;
class Teacher{
	public:
		string name;
		Teacher(){
			cout << "In Teacher class.";
		}
};
class Student : public Teacher{
	public:
		Student(){
			cout << "In Student class.";
		}
		int id;
};	
int main(){
	Student ob; //Line 1
	ob.name = "abcde"; //Line 2
	ob.id = 12345;
	return 0;
}

Options:
In Student class.
In Teacher class.In Student class..         ****************************
Error in line 1
Error in line 2

Ans:
--------------------------------------------------------
Q.2
Find the output
#include<iostream>
#include<string>
using namespace std;
class Bank{
    public:
        string bankName,area;
        Bank(){
            cout << "inside constructor.";
        };
};    
int main(){
	Bank bank;
	bank = "SBI.";//bank.bankName = "SBI.";
    cout << bank.bankName;
	return 0;
}
options:
inside constructor.SBI.
inside constructor.
SBI.
Error *******************************
Ans:
--------------------------------------------------------
Q. 3
Find the output
#include<iostream>
using namespace std;
class Loan{
	public:
		Loan(){
			cout << "Inside loan.";
		}
};
class HomeLoan : public Loan{
	public:
		HomeLoan():Loan(){
		}
};

int main(){
	HomeLoan homeLoan;
	return 0;
}
options:
No output
Compilation error
Inside loan.                **************************
Runtime error
Ans:
--------------------------------------------------------
Q. 4
Find the output

#include<iostream>
using namespace std;
class Base {
    public:
	void Print()    {
        cout << "Base.";
    }
};class Derived : public Base {
    public:
	void Print()
    {
        cout << "Derived.";
    }
};void check(Base* o){
	o->Print();
}
int main(){
	Base* x = new Base();
	Base* y = new Derived();
	Derived* z = new Derived();
	check(x);
	check(y);
	check(z);
	return 0;
}
Options:
Base.Derived.Derived.
Base.Base.Derived.
Base.Base.Base.*************************
Runtime Error
Ans: 
--------------------------------------------------------
Q. 5
Find the output
#include<iostream>
using namespace std;
class Base {
    public:
	void Print()    {
        cout << "Base.";
    }
};
class Derived : public Base {
    public:
	void Print()    {
        cout << "Derived.";
    }
};
class GrandChild : public Derived {
    public:
	void Print()    {
        cout << "Grand Child.";
    }
};

void check(Base* o)
{
	o->Print();
}
int main(){
	Base* x = new Base();
	Base* y = new Derived();
	Derived* z = new Derived();
	Base* r = new GrandChild();
	Derived* s = new GrandChild();
	GrandChild* t = new GrandChild();
	check(x);
	check(y);
	check(z);
	check(r);
	check(s);
	check(t);
	return 0;
}
Options:
Base.Derived.Derived.Grand Child.Grand Child.Grand Child.
Base.Base.Derived.Base.Derived.Grand Child.
Base.Base.Base.Base.Base.Base.      *****************************
Runtime Error
Ans: 
--------------------------------------------------------
Q:6
Which is a wrong keyword as access modifier?
Options:
public
static          ****************************
protected
private	
Ans: 
--------------------------------------------------------
Q. 7

Class X : public Y, public Z {}

shows what kind of a relationship ?
Options:
X is a Y, X is a Z                      *************************
X has a Z
X is a Y, has a Z
None of these

Ans: 
--------------------------------------------------------
Q. 8
Method overloading does not allow:
Options:
Difference in no of arguments
Difference in arguments data type
Difference in return type               *******************
Difference in method name               *******************

Ans: 
--------------------------------------------------------
Q. 9
If a common property(attribute/member data) is referred by many objects of same class,
then that property must be declared as _______ in class.
Options:
static                                              *********************
void            XXXXXXXXXXXXXXXXXX
const           XXXXXXXXXXXXXXXXXXXX
virtual         XXXXXXXXXXXXXXXXXXXX
Ans: 
--------------------------------------------------------
Q. 10
Find the output :
#include<iostream>
using namespace std;
class X
{
	public:
		static void staticMethod()
		{
			cout << "Class X.";
		}
};
class Y :public X
{
	public:
		static void staticMethod()
		{
			cout << "Class Y.";
		}
};
int main(){
	Y::staticMethod();
	X *x = new Y();
	x->staticMethod();
	return 0;
}
Options:
Class Y.Class Y.
Class X.Class X.
Class X.Class Y.
Class Y.Class X.***********************
Ans:
--------------------------------------------------------
11
Which of the function can be called without object

private function
abstract function
static function         *******************
None

Ans:
---------------------------------------------------
12
A constructor cannot be defined under private section of a class.
a)	The above statement is false    *****************
b)	The above statement is true     
c)	Only member functions of the class can declare the objects of classes containing constructors 
under private section.  ******************
d)	Objects of such a classes cannot be declared.    *************           [outside]

Options:
a) only                                 ******
b) only
c) only                                 ******
d) only                                 ******
(a), (c) and (d) are true.              ******          ****************

Ans: Manual Review
--------------------------------------------------------
13
State true or false: A ‘this’ pointer is used to access the static members of a class.
True    
False       ***************************

Ans:
--------------------------------------------------------
14
What is the correct syntax to declare a class?
class A {};                     **************************
class B {}
class C;
none of the above
Ans: 

--------------------------------------------------------
15
A friend function can access only private members of a class
it can access only public members
it can also access protected members
it can access only derived members
it can access all the members of the class to which it is a friend.     *********************
Ans: 
--------------------------------------------------------

--------------------------------------------------------

--------------------------------------------------------

--------------------------------------------------------

--------------------------------------------------------

--------------------------------------------------------

--------------------------------------------------------

//Defining a singleton class
#include<iostream>
using namespace std;
class Emp // Singleton -> design pattern (creational pattern)
{		  //              only single instance	
private:
	static Emp* empAddr;	// II
public:
	/*
		//the method is only one which generates the same class object 
        //because constructor is private
		//no other static method is defined to generate the same class object
		//the generated object pointer has to be private and static 

		// III has to ensure it is generating the object only once
	*/
	static Emp& factory() {
		if (empAddr == NULL) {
			empAddr = new Emp();//only once
		}
		return *empAddr;
	}
private:
	int id;
	float salary;
	Emp() {			// I

	}
public:
	void print() {
		cout << this->id << " " << this->salary << endl;
	}
	void setEmp(int id, float salary)
	{
		this->id = id;
		this->salary = salary;
	}
};
Emp* Emp::empAddr = NULL;

int main() {
	Emp& empOneAlias = Emp::factory();
	empOneAlias.setEmp(101, 3000.0f);	

	Emp& empTwoAlias = Emp::factory();
	empOneAlias.setEmp(102, 4000.0f);

	empOneAlias.print();
	empTwoAlias.print();

	cout << &empOneAlias << " " << &empTwoAlias << endl;
	return 0;
}

--------------------------------------------------------

//Defining a singleton class
#include<iostream>
using namespace std;
class Bank { 
private:
	static Bank* bankAddr;
public:
	static Bank& factory() {
		if (Bank::bankAddr == nullptr) {//NULL
			Bank::bankAddr = new Bank();
		}
		return *Bank::bankAddr;
	}
private: 
	string bankName; 
		
	Bank() {

	}
public:
	void setBankName(string bankName) {
		this->bankName = bankName;
	}
	string getBankName() {
		return this->bankName;
	}
};
Bank* Bank::bankAddr = nullptr;//NULL

int main() {
	Bank& canaraBankCopy = Bank::factory();
	canaraBankCopy.setBankName("Kailasa::Canara Bank.");

	Bank& canaraBank = Bank::factory();
	canaraBank.setBankName("Canara Bank.");

	cout << canaraBankCopy.getBankName() << endl;
	cout << canaraBank.getBankName() << endl;

	return 0;
}
--------------------------------------------------------
//Defining a singleton class
#include<iostream>
using namespace std;
class Finance {
private:
	static Finance* financeAddr;
public:
	static Finance& factory() {
		if (Finance::financeAddr == nullptr) {//NULL
			Finance::financeAddr = new Finance();
		}
		return *Finance::financeAddr;
	}
private: 
	string financeProviderName;
		
	Finance() {

	}
public:
	void setFinanceProviderName(string financeProviderName) {
		this->financeProviderName = financeProviderName;
	}
	string getFinanceProviderName() {
		return this->financeProviderName;
	}
};
Finance* Finance::financeAddr = nullptr;//NULL

int main() {
	Finance& canaraBankFinanceCopy = Finance::factory();
	canaraBankFinanceCopy.setFinanceProviderName("Kailasa::Canara Bank Finance.");

	Finance& canaraBankFinance = Finance::factory();
	canaraBankFinance.setFinanceProviderName("Canara Bank Finance.");

	cout << canaraBankFinanceCopy.getFinanceProviderName() << endl;
	cout << canaraBankFinance.getFinanceProviderName() << endl;

	return 0;
}
--------------------------------------------------------