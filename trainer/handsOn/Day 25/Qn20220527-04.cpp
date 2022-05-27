//Remove duplicate consecutive numbers from given number array
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int N;
    int numbers[] = {10,10,20,20,20,30,30,10,10,15,15,15,15,15,20,20};
	//output 10 20 30 10 15 20
	N = sizeof(numbers)/sizeof(int);
    
        
    auto last = unique(numbers,numbers+N);
    for_each(numbers,last,[](char e){cout << e << " ";});
    //cout << endl << nameOne << endl;
    
    return 0;
}