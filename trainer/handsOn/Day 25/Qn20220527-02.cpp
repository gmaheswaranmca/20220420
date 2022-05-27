//Check given string is palindrome or not
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    char nameOne[256] = "malayalam";//malayalam madam maheswaran palindrome
    char nameTwo[256];
    int nameOneLen = strlen(nameOne);
    strcpy(nameTwo,nameOne);
    reverse(nameTwo,nameTwo+nameOneLen);
    
    //cout << nameOne << endl << nameTwo << endl;
    
    if(strcmp(nameOne,nameTwo)==0){
        cout << "The given word is palindrome." << endl;
    }
    else{
        cout << "The given word is not palindrome." << endl;
    }
        
    return 0;
}
