Duration: 30 minutes
Score: 30 marks
Q1:
Given N rectanges of attributes{length,breath}, 
Find sum of areas of all rectangles

Note: Define dynamic array for the rectange structure
Here, you have to define a function to calculate areas sum
	long findAreasSum(rect_t rectList[],int& rectCount);
Where, rect_t typedef name for the 
	struct _rect_t{int length; int breath;};
    
Initial Code:
#include<iostream>
using namespace std;
struct _rect_t{int length; int breath;};
typedef struct _rect_t	rect_t;
long findAreasSum(rect_t rectList[],int& rectCount){
	/* CODE HERE: to find Sum of Areas of rectList and return the Sum */
}
int main(){
	int N;
	cout << "Enter number of rectangles:";
	cin >> N;
	rect_t* rectangles = /*CODE HERE:C++ Dynamic Array of size N*/;
	for(int I = 0; I < N; I++){
		cout << "Rectangle at " << I << ":" << endl;
		cout << "Length:"; cin >> rectangles[I].length;
		cout << "Breath:"; cin >> rectangles[I].breath;
	}
    long sum = findAreasSum(rectangles,N);
	cout << "Sum of areas of all rectangles is " << sum << endl;
	/*CODE HERE:Free C++ Dynamic Array*/
	rectangles = NULL;
	return EXIT_SUCCESS;
}    
Test Case:
Enter number of rectangles:2
Rectangle at 0:
Length:2
Breath:3
Rectangle at 1:
Length:3
Breath:4
Sum of areas of all rectangles is 18
