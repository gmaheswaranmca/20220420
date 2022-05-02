Duration: 15 minutes
Score: 15 marks
Q2:
1.Find either square or cube of a number N 
using function pointer
to the functions 
	int findSquare(int& num);
	int findCube(int& num);
	to find square and cube respectively.
And,    
int findPower(int& num, int (*givePower) (int&));
receives a number and address of either findSquare or findCube
as arguments and returns the square or cube respectively.
    
Initial Code:
#include<iostream>
using namespace std;
int findSquare(int& num){
    return num * num;
}    
int findCube(int& num){
    return num * num * num;
}
int findPower(int& num, int (*givePower) (int&)){
    /* Code Here */
}
int main(){
	int N;
	cout << "Enter number:";
	cin >> N;
    
    int menu;
    cout << "Enter choice(1-Square, 2-Cube):";
    cin >> menu;
    
    switch(menu){
        case 1:
            cout << "square is " << /* call findPower pass N and findSquare */;
            break;
        case 2:
            cout << "cube is " << /* call findPower pass N and findCube */;
            break;
    }
    
	return EXIT_SUCCESS;
}   

Test Case 1:
Enter number:4
Enter choice(1-Square, 2-Cube):2
cube is 64

Test Case 2:
Enter number:3
Enter choice(1-Square, 2-Cube):1
square is 9

