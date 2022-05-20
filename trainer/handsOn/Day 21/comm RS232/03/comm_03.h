#pragma once
#include <Windows.h>    // Includes the functions for serial communication via RS232
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define EX_FATAL 1
namespace comm_03
{
	// Prototype the functions to be used
	void initPort(HANDLE* hCom, wchar_t* COMPORT, int nComRate, int nComBits, COMMTIMEOUTS& timeout);
	void purgePort(HANDLE* hCom);
	void outputToPort(HANDLE* hCom, LPCVOID buf, DWORD szBuf);
	DWORD inputFromPort(HANDLE* hCom, LPVOID buf, DWORD szBuf);

	// Sub functions
	void createPortFile(HANDLE* hCom, wchar_t* COMPORT);
	int SetComParms(HANDLE* hCom, int nComRate, int nComBits, COMMTIMEOUTS& timeout);

	int main();
}

