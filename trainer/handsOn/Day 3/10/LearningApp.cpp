#include <iostream>
using namespace std;

int findSumOfThree(int a=2, int b=10, int c=5) {
	return a + b + c;
}
int main()
{
	cout << findSumOfThree() << '\n';
	cout << findSumOfThree(15) << '\n';
	cout << findSumOfThree(15,20,30) << '\n';
	return 0;
}