#include "tcpsercli_02.h"
#include<iostream>
#include<string>

using namespace std;
namespace tcpsercli_03 {
	const char ipAddr[256] = "127.0.0.1";
	int __cdecl mainClient()
	{
		WSADATA wsaData;
		SOCKET ConnectSocket = INVALID_SOCKET;


		struct addrinfo* result = NULL;
		struct addrinfo* ptr = NULL;
		struct addrinfo hints;

		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;

		const char* sendbuf = "this is a test";

		int iResult;



		// Validate the parameters
		/*if (argc != 2) {
			printf("usage: %s server-name\n", argv[0]);
			return 1;
		}*/

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
			return 1;
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;


		// Resolve the server address and port
		//iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
		iResult = getaddrinfo(ipAddr, DEFAULT_PORT, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL;ptr = ptr->ai_next) {

			// Create a SOCKET for connecting to server
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
				return 1;
			}

			// Connect to server.
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (ConnectSocket == INVALID_SOCKET) {
			printf("Unable to connect to server!\n");
			WSACleanup();
			return 1;
		}




		int firstNum;
		int secondNum;
		int sumOfNumbers;

		do {
			cout << "First Num:"; cin >> firstNum;
			cout << "Second Num:"; cin >> secondNum;
			
			// Send an initial buffer
			iResult = send(ConnectSocket, (char*)&firstNum, sizeof(int), 0);
			iResult = send(ConnectSocket, (char*)&secondNum, sizeof(int), 0);
			if (iResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}

			//printf("Bytes Sent: %ld\n", iResult);
			cout << "waiting....";


			// Receive until the peer closes the connection
			char temp[DEFAULT_BUFLEN];
			iResult = recv(ConnectSocket, temp, DEFAULT_BUFLEN, 0);
			memcpy(&sumOfNumbers, temp, sizeof(int));
			
			if (iResult > 0)
				cout << "\r(Server): " << sumOfNumbers << endl;
			else if (iResult == 0)
				printf("Connection closed\n");
			else
				printf("recv failed with error: %d\n", WSAGetLastError());

			break;
		} while (iResult > 0);

		// shutdown the connection since no more data will be sent
		iResult = shutdown(ConnectSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}

		// cleanup
		closesocket(ConnectSocket);
		WSACleanup();

		return 0;
	}
	int __cdecl mainServer()
	{
		WSADATA wsaData;
		SOCKET ListenSocket = INVALID_SOCKET;
		SOCKET ClientSocket = INVALID_SOCKET;

		struct addrinfo* result = NULL;
		struct addrinfo hints;


		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;



		int iResult;
		int iSendResult;








		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
			return 1;
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		// Resolve the server address and port
		iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		// Create a SOCKET for connecting to server
		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			return 1;
		}

		// Setup the TCP listening socket
		iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			printf("bind failed with error: %d\n", WSAGetLastError());
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		freeaddrinfo(result);

		iResult = listen(ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR) {
			printf("listen failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		// Accept a client socket
		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		// No longer need server socket
		closesocket(ListenSocket);
		int firstNum;
		int secondNum;
		int sumOfNumbers;
		// Receive until the peer shuts down the connection
		do {
			char temp[DEFAULT_BUFLEN];
			iResult = recv(ClientSocket, temp, DEFAULT_BUFLEN, 0);
			memcpy(&firstNum, temp, sizeof(int));
			iResult = recv(ClientSocket, temp, DEFAULT_BUFLEN, 0);
			memcpy(&secondNum, temp, sizeof(int));
			sumOfNumbers = firstNum + secondNum;
			if (iResult > 0) {
				cout << firstNum  << " + " << secondNum << " is " << sumOfNumbers << endl;
				
				// Echo the buffer back to the sender
				iSendResult = send(ClientSocket, (char*)&sumOfNumbers, sizeof(int), 0);
				if (iSendResult == SOCKET_ERROR) {
					printf("send failed with error: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					return 1;
				}
				cout << "waiting...";
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			break;
		} while (iResult > 0);

		// shutdown the connection since we're done
		iResult = shutdown(ClientSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed with error: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}

		// cleanup
		closesocket(ClientSocket);
		WSACleanup();

		return 0;
	}
	int __cdecl main()
	{
		int menu;
		cout << "Enter option(1-Server,2-Client):"; cin >> menu;
		if (1 == menu) {
			return mainServer();
		}
		else if (2 == menu) {
			return mainClient();
		}

		return 0;
	}
}