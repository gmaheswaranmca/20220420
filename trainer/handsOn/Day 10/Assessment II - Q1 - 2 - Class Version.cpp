#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
#include<iostream>
using namespace std;
class rect_t { 
private:
	int length; 
	int breath; 
public:
	friend long findAreasSum(rect_t rectList[], int& rectCount);
	friend int main();
	long findArea();
};
long rect_t::findArea() {
	return ((long)this->length * (long)this->breath);
}

long findAreasSum(rect_t rectList[], int& rectCount) {
	long sum=0;
	for (int I = 0;I < rectCount;I++) {
		//long area = ((long)rectList[I].length * (long)rectList[I].breath);
		sum += rectList[I].findArea();
	}
	return sum;
}
int main() {
	int N;
	cout << "Enter number of rectangles:";
	cin >> N;
	rect_t* rectangles = new rect_t[N];
	for (int I = 0; I < N; I++) {
		cout << "Rectangle at " << I << ":" << endl;
		cout << "Length:"; cin >> rectangles[I].length;
		cout << "Breath:"; cin >> rectangles[I].breath;
	}
	long sum = findAreasSum(rectangles, N);
	cout << "Sum of areas of all rectangles is " << sum << endl;
	delete[] rectangles;
	rectangles = NULL;
	return EXIT_SUCCESS;
}