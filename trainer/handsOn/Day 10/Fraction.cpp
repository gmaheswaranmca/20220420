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
	Fraction operator+(const Fraction& second);
	Fraction operator-(const Fraction& second);
	Fraction operator*(const Fraction& second);
	Fraction operator/(const Fraction& second);
	//Fraction operator%(const Fraction& second);
	Fraction operator+();
	Fraction operator-();

	Fraction operator++();//pre 
	Fraction operator++(int);//post
	Fraction operator--();//pre 
	Fraction operator--(int);//post

	void operator=(const Fraction& second);
	void operator+=(Fraction& second);

	friend ostream& operator<<(ostream& output, Fraction& first); //[2/3]
};
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
Fraction fOne(1, 1);
void Fraction::operator=(const Fraction& second) {
	numerator = second.numerator;
	denominator = second.denominator;
}
Fraction Fraction::operator+(const Fraction& second) {
	Fraction& first = *this;
	Fraction res;
	res.numerator = first.numerator * second.denominator + second.numerator * first.denominator;
	res.denominator = first.denominator * second.denominator;
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

Fraction Fraction::operator++() {
	Fraction& first = *this;
	Fraction res;
	first = first + fOne;
	res = first;
	return res;
}

Fraction Fraction::operator++(int) {
	Fraction& first = *this;
	Fraction res = first;
	first = first + fOne;
	return res;
}

Fraction Fraction::operator--() {
	Fraction& first = *this;
	Fraction res;
	first = first - fOne;
	res = first;
	return res;
}

Fraction Fraction::operator--(int) {
	Fraction& first = *this;
	Fraction res = first;
	first = first - fOne;
	return res;
}

void Fraction::operator+=(Fraction& second) {
	Fraction& first = *this;
	first = first + second;
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
	Fraction f5 = ((f1 + f2) - f3) * f4;
	cout << f5 << endl;
	Fraction f6 = f5++;
	Fraction f7 = ++f5;
	Fraction f8 = f5--;
	Fraction f9 = --f5;
	Fraction f10 = -f1;
	Fraction f11 = +f1;
	Fraction f12;
	f12 = f1;
	f12 += f3;

	cout << f5 << f6 << f7 << f8 << f9 << f10 << f11 << f12 << endl;

	return EXIT_SUCCESS;
}