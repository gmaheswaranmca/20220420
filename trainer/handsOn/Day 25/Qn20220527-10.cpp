Printing Number pattern
Get the integer value from user and print the following pattern
If the input is not positive and 
                not between 1 and 10 
Print Not possible

Input:
 	5
Output:
15                          1
14	13                      2
12	11	10                  3
9	8	7	6               4
5	4	3	2	1           5=15   1+2+3+...+N = N*(N+1)/2   for 5 = 5*(6/2)=15
                                   for I -> 1 to N 
                                        sum of I    
                                        
                                   patterns start at sumOfI


Test Case 4:
Input:
4
Output:
10
9	8
7	6	5
4	3	2	1


Test Case 2:
Input:
3
Output:
6
5	4
3	2	1


Test Case 3:
Input:
11
Output:
Not Possible

Test Case 4:
Input:
-5
Output:
Not Possible


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    int data = N * (N+1) / 2;//sum of natural numbers till N
    for(int I=1;I<=N;I++){
        for(int J=1; J<=I; J++){
            cout << setw(2) << data-- << setw(1) << " ";
        }
        cout << endl;
    }

    return 0;
}

*
**
***
****
*****

#include <iostream>
using namespace std;

int main()
{
    int N = 5;
    for(int I=1;I<=N;I++){
        //I times the '*'
        for(int J=1; J<=I; J++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


---------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=1;I<=N;I++){
        //I times the '*'
        cout << setfill('*') << setw(I) << left << "" << endl;
    }

    return 0;
}


*****    
****
***
**
*
#include <iostream>
using namespace std;

int main()
{
    int N = 5;
    for(int I=N;I>=1;I--){
        //I times the '*'
        for(int J=1; J<=I; J++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}   
    
*****    
 ****
  ***
   **
    *
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=N;I>=1;I--){
        //(N-I)spaces, I '*'s
        cout << setw(N-I) << "";
        for(int J=1; J<=I; J++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}          
-----------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=N;I>=1;I--){
        cout << setw(N-I) << setfill(' ') << left << "" << setw(0);
        cout << setw(I) << setfill('*') << right << "" << endl;
        cout << endl;
    }

    return 0;
}  
    *
   **
  ***
 ****
*****
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=1;I<=N;I++){
        cout << setw(N-I) << setfill(' ') << left << "" << setw(0);
        cout << setw(I) << setfill('*') << right << "";
        cout << endl;
    }

    return 0;
}  
    *           N-I spaces, I '*'s
   ***          N-I spaces, I '*'s, I-1 '*'s
  *****
 *******
*********
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=1;I<=N;I++){
        cout << setw(N-I) << setfill(' ') << left << "" << setw(0);
        cout << setw(I) << setfill('*') << left << "" ;
        cout << setw(I-1) << setfill('*') << left << "" ;
        cout << endl;
    }

    return 0;
}    

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 5;
    for(int I=1;I<=N;I++){
        cout << setw(N-I) << setfill(' ') << left << "" << setw(0);
        cout << setw(I) << setfill('*') << left << "" ;
        cout << setw(I-1) << setfill('*') << left << "" ;
        cout << endl;
    }
    for(int I=N-1;I>=1;I--){
        cout << setw(N-I) << setfill(' ') << left << "" << setw(0);
        cout << setw(I) << setfill('*') << left << "" ;
        cout << setw(I-1) << setfill('*') << left << "" ;
        cout << endl;
    }
    return 0;
}      
    
    



