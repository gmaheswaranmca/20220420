#include <iostream>

void printAge(int& ageAlias) {
	std::cout << ageAlias;
}

int main()
{
    int age = 43;
	printAge(age);
	//printAge(56);
	return 0;
    
	return 0;
}