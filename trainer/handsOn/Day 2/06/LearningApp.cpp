#include <iostream>

int main()
{
    int age = 43;
	int& x = age;
	int* pAge = &age;
    
	using std::cout;
	using std::endl;
    
	cout << age << endl;
	cout << *pAge << endl; 
	cout << x << endl;
    
	*pAge = 23;
	cout << age << endl;
    
	x = 42;
	cout << age << endl;
    
    
	return 0;
}