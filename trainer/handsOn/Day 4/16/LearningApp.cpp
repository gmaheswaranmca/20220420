#define MAX_ROWS 10
#define MAX_COLS 10        
#include <iostream>
using namespace std;

int main(){
    float salaryMatrix[MAX_ROWS][MAX_COLS];
    int rowCount=3, colCount=5;
    cout << "Enter rows count:"; 
    cin >> rowCount;
    
    cout << "Enter columns count:"; 
    cin >> colCount;
    
    cout << "Enter data for the matrix of size " << rowCount << "x" << colCount << endl;
    for(int rowIndex = 0; rowIndex < rowCount; rowIndex++){ 
        for(int colIndex =0; colIndex < colCount; colIndex++){ 
            cout << "Element at row " << rowIndex << " and col at " << colIndex << ":";
            cin >> salaryMatrix[rowIndex][colIndex];
        }
    }    
    cout << "The matrix:" << endl;
    for(int rowIndex = 0; rowIndex < rowCount; rowIndex++){ 
        for(int colIndex =0; colIndex < colCount; colIndex++){ 
            cout << salaryMatrix[rowIndex][colIndex] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
