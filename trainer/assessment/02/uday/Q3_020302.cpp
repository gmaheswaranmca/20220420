Duration: 15 minutes
Score: 15 marks
Q:
In the person structure{firstName, lastName, fullName}
swap the firstName and lastName 
And after swap find the fullName inside the function doProcess and call in main 

Use: C-strings for firstName, lastName, fullName
struct _person_t{
	char firstName[256];
	char lastName[256];
	char fullName[256];
};
typedef struct _person_t person_t;

Use: the following function to those changes
void doProcess(person_t* person){
    /* Do here the swap and then update of names */
}

Use: c-string library to use strlen, strcat, strcpy if required

For Input/Output refer the test case below.

Test Case:
Enter First Name: Rahul
Enter Last Name: Dravid
First Name: Dravid 
Last Name: Rahul 
Full Name: Dravid Rahul  


