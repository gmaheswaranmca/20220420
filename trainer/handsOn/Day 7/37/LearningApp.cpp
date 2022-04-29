//Find sum of salaries using pass by array, pass by pointer
//and using subscript operator, indirection operator, pointer arithmetic 
#include<iostream>
using namespace std;

float  findSumOfSalariesv1(float sal[], int size) {
	float sum = 0.0f;
	for (int I = 0; I < size; I++) {
		sum = sum + sal[I];
	}
	return sum;
}
float  findSumOfSalariesv2(float *sal, int size){
	float sum = 0.0f;
	for (int I = 0; I < size; I++) {
		sum = sum + sal[I];
	}
	return sum;
}
float  findSumOfSalariesv3(float* sal, int size) {
	float sum = 0.0f;
	for (int I = 0; I < size; I++) {
		sum = sum + (*sal);
		sal++;
	}
	return sum;
}
float  findSumOfSalariesv4(float* sal, int size) {
	float sum = 0.0f;
	for (int I = 0; I < size; I++) {
		sum = sum + (*(sal+I));
	}
	return sum;
}
float  findSumOfSalariesv5(float sal[], int size) {
	float sum = 0.0f;
	for (int I = 0; I < size; I++) {
		sum = sum + (*(sal + I));
	}
	return sum;
}
int main() {
	float salaries[5] = { 1000.0f, 1200.f, 1100.0f, 1300.0f, 1150.0f};//8 byte
					//		800		808		816		
	float sum1 = findSumOfSalariesv1(salaries, 5);
	float sum2 = findSumOfSalariesv2(salaries, 5);
	float sum3 = findSumOfSalariesv3(salaries, 5);
	float sum4 = findSumOfSalariesv4(salaries, 5);
	float sum5 = findSumOfSalariesv4(salaries, 5);

	cout << "v1-The sum of the salaries is " << sum1 << endl;
	cout << "v2-The sum of the salaries is " << sum2 << endl;
	cout << "v3-The sum of the salaries is " << sum3 << endl;
	cout << "v4-The sum of the salaries is " << sum4 << endl;
	cout << "v5-The sum of the salaries is " << sum5 << endl;
	return EXIT_SUCCESS;
}