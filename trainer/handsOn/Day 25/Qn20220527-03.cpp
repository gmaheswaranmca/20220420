//Remove consecutive duplicate characters from given string 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    char nameOne[256] = "aabbbbccddd";
    
    int nameOneLen = strlen(nameOne);
   
        
        
    auto last = unique(nameOne,nameOne+nameOneLen);
    for_each(nameOne,last,[](char e){cout << e ;});
    cout << endl << nameOne << endl;
    
    return 0;
}
