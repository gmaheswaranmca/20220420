/*Double pointer
Give proper Namings to the pointers for better readability and understanding
-------------------------------------------------
Create a dynamic memory and set the value 
Print its address and the data 
Define a function 
    o to delete the block just created in main()
    o to have new memory block out of the function but into the same pointer held old block
    o set the value 
After the function we should print the new block's address and data      
*/
using namespace std;
void createNew(int** numAddrAddr) { //30000
    int *numAddr = *numAddrAddr; //numAddr[9020]40000
    
	delete numAddr; 
	numAddr = NULL;

	numAddr = new int;                  //[200]9020
	*numAddr = 200;
    
    *numAddrAddr = numAddr;     
}

int main() {
	int* dataAddr = new int; // dataAddr[9020]30000     [100x]5670
	*dataAddr = 100;               
	cout << "Address in the dataAddr: " << dataAddr << endl;
	cout << "Data by dataAddr: " << (*dataAddr) << endl;
	createNew(&dataAddr); //30000
	cout << "Address in the dataAddr: " << dataAddr << endl; 
	cout << "Data by dataAddr: " << (*dataAddr) << endl;

	return EXIT_SUCCESS;
}