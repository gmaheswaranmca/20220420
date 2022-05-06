#include<iostream>
using namespace std;
class Fraction {	//	a/b	
private:
	int numerator;		//a 
	int denominator;	//b
	int gcf();
public:
	Fraction();			//0/1	right		0/0 wrong
	Fraction(int numerator, int denominator);
    //Binary Arithmetic Operators 
	Fraction operator+(const Fraction& second);//c=a+b -> c=a.operator+(b)  userObj
	Fraction operator-(const Fraction& second);//c=a-b -> c=a.operator-(b)  userObj
	Fraction operator*(const Fraction& second);
	Fraction operator/(const Fraction& second);
	//Fraction operator%(const Fraction& second);
    //Unary + and Unary -
	Fraction operator+();
	Fraction operator-();   //b=-a; -> a.operator-()    userObj
    //Pre and Post increment/decrement 
	Fraction operator++();//pre         b=++a; -> a=a+1;b=a; -> a.operator++()  userObj
	Fraction operator++(int);//post     b=a++;  -> b=a;a=a+1; -> a.operator++(0) userObj
	Fraction operator--();//pre 
	Fraction operator--(int);//post
    //Binary Assignment and Binary Short hand assignment
	void operator=(const Fraction& second); //a=b   -> a.operator=(b)  noReturn
	void operator+=(Fraction& second);//a+=b; -> a=a+b; -> a.operator+=(b) noReturn 
    //Binary Relational Operator
	bool operator<(const Fraction& second); //a<b   -> a.operator<(b)  bool 

	friend ostream& operator<<(ostream& output, Fraction& first); //[2/3]
};

Fraction fOne(1, 1);

int Fraction::gcf() {
	Fraction& first = *this;
	int n1 = first.numerator;
	int n2 = first.denominator;
	n1 = (n1 > 0) ? n1 : -n1;
	n2 = (n2 > 0) ? n2 : -n2;

	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	return n1;
}

Fraction::Fraction() {
	Fraction& first = *this;
	first.numerator = 0;
	first.denominator = 1;
}
Fraction::Fraction(int numerator, int denominator) {
	Fraction& first = *this;
	first.numerator = numerator;
	first.denominator = denominator;
}


Fraction Fraction::operator+(const Fraction& second) {
	Fraction& first = *this;
	Fraction res;
	//cout << "Start We are at the binary +" << endl;
	res.numerator = first.numerator * second.denominator + second.numerator * first.denominator;
	res.denominator = first.denominator * second.denominator;
	//cout << "End We are at the binary +" << endl;
	return res;
}
Fraction Fraction::operator-(const Fraction& second) {
	Fraction& first = *this;
	Fraction res;
	res.numerator = first.numerator * second.denominator - second.numerator * first.denominator;
	res.denominator = first.denominator * second.denominator;
	return res;
}
Fraction Fraction::operator*(const Fraction& second) {//c/d
	Fraction& first = *this;//a/b
	Fraction res;
	res.numerator = first.numerator * second.numerator;//ac
	res.denominator = first.denominator * second.denominator;//bd
	return res;	//ac/bd
}
Fraction Fraction::operator/(const Fraction& second) {//c/d
	Fraction& first = *this;//a/b
	Fraction res;
	res.numerator = first.numerator * second.denominator;//ad
	res.denominator = first.denominator * second.numerator;//bc
	return res;	//ad/bc
}
//Fraction operator%(const Fraction& second);
Fraction Fraction::operator+() {
	Fraction& first = *this;//a/b
	Fraction res(+first.numerator, first.denominator);
	return res;
}
Fraction Fraction::operator-() {
	Fraction& first = *this;
	Fraction res(-first.numerator, first.denominator);
	return res;
}

Fraction Fraction::operator++() {//pre increment b=++a;
	Fraction& first = *this;
	Fraction res;
	//cout << "Start We are at pre increment" << endl;
	first = first + fOne;	// a = a + 1;	// first.operator=(first.operator+(fOne))
	//cout << "End We are at pre increment" << endl;
	res = first;			// b = a;
	return res;
}
/*
Start We are at pre increment
Start We are at the binary +
End We are at the binary +
Start We are at the binary =
End We are at the binary =
End We are at pre increment
*/

Fraction Fraction::operator++(int) {//post increment b=a++;
	Fraction& first = *this;
	Fraction res = first;	// b = a;
	first = first + fOne;	// a = a + 1;
	return res;
}

Fraction Fraction::operator--() {	//pre decrement b=--a
	Fraction& first = *this;	
	Fraction res;
	first = first - fOne;		// a = a- 1;
	res = first;				// b = a;
	return res;
}

Fraction Fraction::operator--(int) {//post decrement b=a--
	Fraction& first = *this;
	Fraction res = first;	//b = a
	first = first - fOne;	//a = a - 1
	return res;
}

void Fraction::operator=(const Fraction& second) {
	Fraction& first = *this;
	//cout << "Start We are at the binary =" << endl;
	first.numerator = second.numerator;
	first.denominator = second.denominator;
	//cout << "End We are at the binary =" << endl;
}

void Fraction::operator+=(Fraction& second) {//a+=b; => a=a+b
	Fraction& first = *this;
	first = first + second;
}
bool Fraction::operator<(const Fraction& second) {	//a=4,b=5   a<b -> a-b=-1<0
	Fraction& first = *this;
	Fraction third = first - second; //1/2 - 3/4  ->  -1/4 | 3/4-1/2 -> 1/2
	return third.numerator < 0;//false for -1/4   | true for 1/2
}
ostream& operator<<(ostream& output, Fraction& first) {
	int factor = first.gcf();
	first.numerator /= factor;
	first.denominator /= factor;
	output << "[" << first.numerator << "/" << first.denominator << "]";
	return output;
}
//define 
int main() {
	Fraction f1(1, 4), f2(3, 4), f3(1, 2), f4(1, 8);
	cout << f1 << f2 << f3 << f4 << endl;
	Fraction f5 = ((f1 + f2) - f3) * f4;//1/16
	cout << f5 << endl;
	Fraction f6 = f5++;//f6=1/16; f5=1/16 + 1/1=17/16
	Fraction f7 = ++f5;//f5=17/16 + 1/1=33/16	f7=33/16
	Fraction f8 = f5--;//f8=33/16    f5=33/16-1/1=17/16
	Fraction f9 = --f5;//f5=17/16-1/1=1/16   f9=1/16
	Fraction f10 = -f1;//f10=-1/4    f1=1/4
	Fraction f11 = +f1;//f10=1/4    f1=1/4
	Fraction f12;
	f12 = f1;//f12=1/4
	f12 += f3;//f12=1/4+1/2 =6/8->3/4

	cout << f5 << f6 << f7 << f8 << f9 << f10 << f11 << f12 << endl;
	cout << (f3 < f2) <<  " " << (f2 < f3) << endl;//1/2 < 3/4 | 3/4 < 1/2

	return EXIT_SUCCESS;
}
//Assignment: Migrate The Overloaded Member Operators to Friend Operators