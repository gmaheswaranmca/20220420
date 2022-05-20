#include "comm_03.h"
namespace comm_03
{
	// Initializes the port and sets the communication parameters
	void initPort(HANDLE* hCom, wchar_t* COMPORT, int nComRate, int nComBits, COMMTIMEOUTS& timeout) {
		createPortFile(hCom, COMPORT);						// Initializes hCom to point to PORT#
		purgePort(hCom);									// Purges the COM port
		SetComParms(hCom, nComRate, nComBits, timeout);		// Uses the DCB structure to set up the COM port
		purgePort(hCom);
	}

	// Purge any outstanding requests on the serial port (initialize)
	void purgePort(HANDLE* hCom) {
		PurgeComm(*hCom, PURGE_RXABORT | PURGE_RXCLEAR | PURGE_TXABORT | PURGE_TXCLEAR);
	}

	// Output/Input messages to/from ports 
	void outputToPort(HANDLE* hCom, LPCVOID buf, DWORD szBuf) {
		int i = 0;
		DWORD NumberofBytesTransmitted;
		LPDWORD lpErrors = 0;
		LPCOMSTAT lpStat = 0;

		i = WriteFile(
			*hCom,										// Write handle pointing to COM port
			buf,										// Buffer size
			szBuf,										// Size of buffer
			&NumberofBytesTransmitted,					// Written number of bytes
			NULL
		);
		// Handle the timeout error
		if (i == 0) {
			printf("\nWrite Error: 0x%x\n", GetLastError());
			ClearCommError(hCom, lpErrors, lpStat);		// Clears the device error flag to enable additional input and output operations. Retrieves information ofthe communications error.	
		}
		else
			printf("\nSuccessful transmission, there were %ld bytes transmitted\n", NumberofBytesTransmitted);
	}

	DWORD inputFromPort(HANDLE* hCom, LPVOID buf, DWORD szBuf) {
		int i = 0;
		DWORD NumberofBytesRead;
		LPDWORD lpErrors = 0;
		LPCOMSTAT lpStat = 0;

		i = ReadFile(
			*hCom,										// Read handle pointing to COM port
			buf,										// Buffer size
			szBuf,  									// Size of buffer - Maximum number of bytes to read
			&NumberofBytesRead,
			NULL
		);
		// Handle the timeout error
		if (i == 0) {
			printf("\nRead Error: 0x%x\n", GetLastError());
			ClearCommError(hCom, lpErrors, lpStat);		// Clears the device error flag to enable additional input and output operations. Retrieves information ofthe communications error.
		}
		else
			printf("\nSuccessful reception!, There were %ld bytes read\n", NumberofBytesRead);

		return(NumberofBytesRead);
	}



	// Sub functions called by above functions
	/**************************************************************************************/
	// Set the hCom HANDLE to point to a COM port, initialize for reading and writing, open the port and set securities
	void createPortFile(HANDLE* hCom, wchar_t* COMPORT) {
		// Call the CreateFile() function 
		*hCom = CreateFile(
			COMPORT,									// COM port number  --> If COM# is larger than 9 then use the following syntax--> "\\\\.\\COM10"
			GENERIC_READ | GENERIC_WRITE,				// Open for read and write
			NULL,										// No sharing allowed
			NULL,										// No security
			OPEN_EXISTING,								// Opens the existing com port
			FILE_ATTRIBUTE_NORMAL,						// Do not set any file attributes --> Use synchronous operation
			NULL										// No template
		);

		if (*hCom == INVALID_HANDLE_VALUE) {
			printf("\nFatal Error 0x%x: Unable to open\n", GetLastError());
		}
		else {
			printf("\nCOM is now open\n");
		}
	}

	int SetComParms(HANDLE* hCom, int nComRate, int nComBits, COMMTIMEOUTS& timeout) {
		DCB dcb;										// Windows device control block
		// Clear DCB to start out clean, then get current settings
		memset(&dcb, 0, sizeof(dcb));
		dcb.DCBlength = sizeof(dcb);
		if (!GetCommState(*hCom, &dcb))
			return(0);

		// Set our own parameters from Globals
		dcb.BaudRate = nComRate;						// Baud (bit) rate
		dcb.ByteSize = (BYTE)nComBits;					// Number of bits(8)
		dcb.Parity = 0;									// No parity	
		dcb.StopBits = ONESTOPBIT;						// One stop bit
		if (!SetCommState(*hCom, &dcb))
			return(0);

		// Set communication timeouts (SEE COMMTIMEOUTS structure in MSDN) - want a fairly long timeout
		memset((void*)&timeout, 0, sizeof(timeout));
		timeout.ReadIntervalTimeout = 500;				// Maximum time allowed to elapse before arival of next byte in milliseconds. If the interval between the arrival of any two bytes exceeds this amount, the ReadFile operation is completed and buffered data is returned
		timeout.ReadTotalTimeoutMultiplier = 1;			// The multiplier used to calculate the total time-out period for read operations in milliseconds. For each read operation this value is multiplied by the requested number of bytes to be read
		timeout.ReadTotalTimeoutConstant = 5000;		// A constant added to the calculation of the total time-out period. This constant is added to the resulting product of the ReadTotalTimeoutMultiplier and the number of bytes (above).
		SetCommTimeouts(*hCom, &timeout);
		return(1);
	}

	// The client - A testing main that calls the functions below
	int main() {
		// Note: Comment out the Tx or Rx sections below to operate in single sided mode

// Declare constants, variables and communication parameters
		const int BUFSIZE = 140;							// Buffer size
		wchar_t COMPORT_Rx[] = L"COM7";						// COM port used for Rx (use L"COM6" for transmit program)
		wchar_t COMPORT_Tx[] = L"COM6";						// COM port used for Rx (use L"COM6" for transmit program)

		// Communication variables and parameters
		HANDLE hComRx;										// Pointer to the selected COM port (Receiver)
		HANDLE hComTx;										// Pointer to the selected COM port (Transmitter)
		int nComRate = 9600;								// Baud (Bit) rate in bits/second 
		int nComBits = 8;									// Number of bits per frame
		COMMTIMEOUTS timeout;								// A commtimeout struct variable

		// Set up both sides of the comm link
		initPort(&hComRx, COMPORT_Rx, nComRate, nComBits, timeout);	// Initialize the Rx port
		Sleep(500);
		initPort(&hComTx, COMPORT_Tx, nComRate, nComBits, timeout);	// Initialize the Tx port
		Sleep(500);

		// Transmit side 
		char msgOut[] = "Hi there person";							// Sent message	
		outputToPort(&hComTx, msgOut, strlen(msgOut) + 1);			// Send string to port - include space for '\0' termination
		Sleep(500);													// Allow time for signal propagation on cable 

		// Receive side  
		char msgIn[BUFSIZE];
		DWORD bytesRead;
		bytesRead = inputFromPort(&hComRx, msgIn, BUFSIZE);			// Receive string from port
		//printf("Length of received msg = %d", bytesRead);
		msgIn[bytesRead] = '\0';
		printf("\nMessage Received: %s\n\n", msgIn);				// Display message from port

		// Tear down both sides of the comm link
		purgePort(&hComRx);											// Purge the Rx port
		purgePort(&hComTx);											// Purge the Tx port
		CloseHandle(hComRx);										// Close the handle to Rx port 
		CloseHandle(hComTx);										// Close the handle to Tx port 

		system("pause");

		return 0;
	}
}


/*

#include"comm_03.h"

int main() {
	return comm_03::main();
}


*/