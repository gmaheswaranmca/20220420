#include "tcpsercli_04.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

namespace tcpsercli_04 {
	//*********************Service***********************************
	MyService::MyService() {

	}
	MyService::~MyService() {

	}
	bool MyService::initApi() {
		this->is_api_not_initialized = false;

		this->is_getaddrinfo_failed = false;
		this->is_socket_failed = false;
		this->is_unable_connect_sever = false;

		this->is_send_failed = false;
		this->is_connection_closed = false;
		this->is_received_failed = false;

		this->is_shutdown_failed = false;

		this->is_bind_failure = false;
		this->is_accept_failure = false;
		this->is_listen_failure = false;

		this->err_code = 0;


		is_socket_failed = true;
		WSADATA wsaData;
		err_code = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (err_code != 0) {
			cout << "WSAStartup failed with error: " << err_code << endl;
			this->is_api_not_initialized = true;
		}
		return !this->is_api_not_initialized;
	}
	bool MyService::closeApi() {
		WSACleanup();
		return true;
	}
	bool MyService::openClient(SOCKET& jobSocket, string ipAddr, string port = DEFAULT_PORT) {
		this->is_getaddrinfo_failed = false;
		this->is_socket_failed = false;
		this->is_unable_connect_sever = false;

		struct addrinfo* result = NULL;
		struct addrinfo* ptr = NULL;
		struct addrinfo hints;
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;


		// Resolve the server address and port
		int err_code = getaddrinfo(ipAddr.c_str(), port.c_str(), &hints, &result);
		if (err_code != 0) {
			this->is_getaddrinfo_failed = true;
			cout << "getaddrinfo failed with error: " << err_code << endl;
			WSACleanup();
			return !this->is_getaddrinfo_failed;
		}

		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL;ptr = ptr->ai_next) {

			// Create a SOCKET for connecting to server
			jobSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (jobSocket == INVALID_SOCKET) {
				is_socket_failed = true;
				cout << "socket failed with error: " << WSAGetLastError() << endl;
				WSACleanup();
				return !is_socket_failed;
			}

			// Connect to server.
			err_code = connect(jobSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (err_code == SOCKET_ERROR) {
				closesocket(jobSocket);
				jobSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}
		freeaddrinfo(result);

		if (jobSocket == INVALID_SOCKET) {
			is_unable_connect_sever = true;
			cout << "Unable to connect to server!" << endl;
			WSACleanup();
			return !is_unable_connect_sever;
		}
		return true;
	}

	
	bool MyService::closeClient(SOCKET& jobSocket) {
		is_shutdown_failed = false;
		// shutdown the connection since no more data will be sent
		err_code = shutdown(jobSocket, SD_SEND);
		if (err_code == SOCKET_ERROR) {
			is_shutdown_failed = true;
			cout << "shutdown failed with error: " << WSAGetLastError() << endl;
			closesocket(jobSocket);
			WSACleanup();
			return !is_shutdown_failed;
		}

		// cleanup
		closesocket(jobSocket);
		return true;
	}
	bool MyService::openServer(SOCKET& listenSocket, SOCKET& jobSocket, string port = DEFAULT_PORT) {
		this->is_getaddrinfo_failed = false;
		this->is_socket_failed = false;
		this->is_bind_failure = false;
		this->is_accept_failure = false;
		this->is_listen_failure = false;


		struct addrinfo* result = NULL;
		struct addrinfo hints;
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		// Resolve the server address and port
		err_code = getaddrinfo(NULL, port.c_str(), &hints, &result);
		if (err_code != 0) {
			is_getaddrinfo_failed = true;
			cout << "getaddrinfo failed with error: " << err_code << endl;
			WSACleanup();
			return !is_getaddrinfo_failed;
		}

		// Create a SOCKET for connecting to server
		listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (listenSocket == INVALID_SOCKET) {
			is_socket_failed = true;
			cout << "socket failed with error: " << WSAGetLastError() << endl;
			freeaddrinfo(result);
			WSACleanup();
			return !is_socket_failed;
		}

		// Setup the TCP listening socket
		err_code = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (err_code == SOCKET_ERROR) {
			is_bind_failure = true;
			cout << "bind failed with error: " << WSAGetLastError() << endl;
			freeaddrinfo(result);
			closesocket(listenSocket);
			WSACleanup();
			return !is_bind_failure;
		}

		freeaddrinfo(result);

		err_code = listen(listenSocket, SOMAXCONN);
		if (err_code == SOCKET_ERROR) {
			is_listen_failure = true;
			cout << "listen failed with error: " << WSAGetLastError() << endl;
			closesocket(listenSocket);
			WSACleanup();
			return !is_listen_failure;
		}

		// Accept a client socket
		jobSocket = accept(listenSocket, NULL, NULL);
		if (jobSocket == INVALID_SOCKET) {
			is_accept_failure = true;
			cout << "accept failed with error:" << WSAGetLastError() << endl;
			closesocket(listenSocket);
			WSACleanup();
			return !is_accept_failure;
		}
		// No longer need server socket
		closesocket(listenSocket);
		return true;
	}

	//*********************Client***********************************
	MyClientService::MyClientService(string host, string port) :MyService(), host(host), port(port) {
		
	}

	MyClientService::~MyClientService() {

	}
	bool MyClientService::doServe() {
		bool isValid = true;
		
		SOCKET jobSocket;
		if (isValid) isValid = this->initApi();
		if (isValid) isValid = this->openClient(jobSocket,this->host, this->port);
		if (isValid) isValid = this->doClientJob(jobSocket);
		if (isValid) isValid = this->closeClient(jobSocket);
		if (isValid) isValid = this->closeApi();
		return isValid;
	}
	
	bool MyClientService::doClientJob(SOCKET& jobSocket) {
		bool result;
		is_send_failed = false;
		is_connection_closed = false;
		is_received_failed = false;
		result = true;

		do {
			this->doJobStepOne(jobSocket);//!!!
			if (err_code == SOCKET_ERROR) {
				is_send_failed = true;
				cout << "send failed with error: " << WSAGetLastError() << endl;
				closesocket(jobSocket);
				WSACleanup();
				result = !is_send_failed;
				return result;
			}

			this->doJobStepTwo(jobSocket);//!!!

			if (err_code > 0) {
				this->doJobStepThree(jobSocket);//!!!
			}
			else if (err_code == 0) {
				cout << "Connection closed" << endl;
				is_connection_closed = true;
				result = !is_connection_closed;
				return result;
			}
			else {
				cout << "recv failed with error: " << WSAGetLastError() << endl;
				is_received_failed = true;
				result = !is_received_failed;
				return result;
			}


			break;
		} while (err_code > 0);
		return result;
	}
	void MyClientService::doJobStepOne(SOCKET& jobSocket) {
		cout << "First Num:"; cin >> firstNum;//JOB LINE
		cout << "Second Num:"; cin >> secondNum;//JOB LINE

		// Send an initial buffer
		err_code = send(jobSocket, (char*)&firstNum, sizeof(int), 0);//JOB LINE
		err_code = send(jobSocket, (char*)&secondNum, sizeof(int), 0);//JOB LINE
	}
	void MyClientService::doJobStepTwo(SOCKET& jobSocket) {
		cout << "waiting....";//JOB LINE
		// Receive until the peer closes the connection
		char temp[DEFAULT_BUFLEN];//JOB LINE
		err_code = recv(jobSocket, temp, DEFAULT_BUFLEN, 0);//JOB LINE
		memcpy(&sumOfNumbers, temp, sizeof(int));//JOB LINE
	}
	void MyClientService::doJobStepThree(SOCKET& jobSocket) {
		cout << "\rSum is " << sumOfNumbers << endl;//JOB LINE
	}

	//*********************Server***********************************
	MyServerService::MyServerService(string port) :MyService(), port(port) {
		
	}

	MyServerService::~MyServerService() {

	}

	bool MyServerService::doServe() {
		bool isValid = true;
		SOCKET listenSocket;
		SOCKET jobSocket;
		if (isValid) isValid = this->initApi();
		if (isValid) isValid = this->openServer(listenSocket, jobSocket, this->port);
		if (isValid) isValid = this->doServerJob(jobSocket);
		if (isValid) isValid = this->closeClient(jobSocket);
		if (isValid) isValid = this->closeApi();
		return isValid;
	}


	bool MyServerService::doServerJob(SOCKET& jobSocket) {
		bool result;
		is_send_failed = false;
		is_connection_closed = false;
		is_received_failed = false;
		result = true;

		do {
			this->doJobStepOne(jobSocket);//!!!

			if (err_code > 0) {
				this->doJobStepTwo(jobSocket);//!!!
			}
			else if (err_code == 0) {
				cout << "Connection closed" << endl;
				is_connection_closed = true;
				result = !is_connection_closed;
				return result;
			}
			else {
				cout << "recv failed with error: " << WSAGetLastError() << endl;
				is_received_failed = true;
				result = !is_received_failed;
				return result;
			}
			// Send an initial buffer
			this->doJobStepThree(jobSocket);//!!!
			if (err_code == SOCKET_ERROR) {
				is_send_failed = true;
				cout << "send failed with error: " << WSAGetLastError() << endl;
				closesocket(jobSocket);
				WSACleanup();
				result = !is_send_failed;
				return result;
			}

			break;

		} while (err_code > 0);

		return result;
	}
	void MyServerService::doJobStepOne(SOCKET& jobSocket) {
		char temp[DEFAULT_BUFLEN];
		err_code = recv(jobSocket, temp, DEFAULT_BUFLEN, 0);
		memcpy(&firstNum, temp, sizeof(int));
		err_code = recv(jobSocket, temp, DEFAULT_BUFLEN, 0);
		memcpy(&secondNum, temp, sizeof(int));
		sumOfNumbers = firstNum + secondNum;
	}
	void MyServerService::doJobStepTwo(SOCKET& jobSocket) {
		cout << firstNum << " + " << secondNum << " is " << sumOfNumbers << endl;
		cout << "waiting...";
	}
	void MyServerService::doJobStepThree(SOCKET& jobSocket) {
		err_code = send(jobSocket, (char*)&sumOfNumbers, sizeof(int), 0);
	}
	//*********************Driver Code***********************************
	int main() {
		int exitCode = EXIT_SUCCESS;
		int menu;
		cout << "Enter option(1-Server,2-Client):"; cin >> menu;
		if (1 == menu) {
			MyServerService server(DEFAULT_PORT);
			exitCode = server.doServe();
		}
		else if (2 == menu) {
			MyClientService client("127.0.0.1", DEFAULT_PORT);			
			exitCode = client.doServe();
		}

		return exitCode;
	}
}