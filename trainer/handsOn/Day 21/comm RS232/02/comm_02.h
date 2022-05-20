#pragma once
#include<windows.h>
#include<iostream>

#define EX_FATAL 1
#define BUFSIZE 140
using namespace std;
namespace comm_02
{
	struct Api {
		static void init(HANDLE* hCom, wchar_t* COMPORT, int nComRate, int nComBits, COMMTIMEOUTS& timeout);
		static void purge(HANDLE* hCom);

		static int setConf(HANDLE* hCom, int nComRate, int nComBits, COMMTIMEOUTS& timeout);
		
		static void open(HANDLE* hCom, wchar_t* COMPORT);
		static void close(HANDLE* hCom);
	};
	struct TransmitterApi :Api {
		static void print(HANDLE* hCom, LPCVOID buf, DWORD szBuf);
	};
	struct ReceiverApi :Api {
		static DWORD read(HANDLE* hCom, LPVOID buf, DWORD szBuf);
	};
	int mainTransmitter();
	int mainReceiver();
	int main();
}