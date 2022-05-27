Finding the array is unique array or duplicate array: 
Get the n values into an array. Find the array is unique or duplicate
Input:
6
6   1  7  0  4  -2
Output:
Unique Array

Input:
10=N
7  0  6  9  1  5  2  3  5  6=Number            
-> "number" to be checked "next numbers" if repeated stop and finalize duplicate
for I -> 0 to <N-1
  for J=I+1 to <N
    compare number at I and number at J 
        if matches stop for duplicate 
Output:
Duplicate Array

Test Case 1:
Input:
5
10   8  -3  34  0
Output:
Unique Array

Test Case 2:
Input:
2
10  10
Output:
Duplicate Array

Test Case 3:
Input:
6
12   34   15   34   0   8
Output:
Duplicate Array

Test Case 4:
Input:
5
-10  -20  -30  -40  -50
Output:
Unique Array

Test Case 5:
Input:
4
12  134  12  34
Output:
Duplicate Array


bool isUnique(int numbers[], int N){
    
}
