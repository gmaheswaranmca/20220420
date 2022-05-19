#pragma once
#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include<iostream>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "8080"

using namespace std;
namespace tcpsercli_04 {
	class MyService {
	public:
		bool is_api_not_initialized;

		bool is_getaddrinfo_failed;
		bool is_socket_failed;
		bool is_unable_connect_sever;

		bool is_send_failed;
		bool is_connection_closed;
		bool is_received_failed;

		bool is_shutdown_failed;

		bool is_bind_failure;
		bool is_accept_failure;
		bool is_listen_failure;
		int err_code;

		MyService();
		~MyService();

		bool initApi();
		bool closeApi();
		bool openClient(SOCKET& jobSocket, string ipAddr, string port);
		
		bool closeClient(SOCKET& jobSocket);
		bool openServer(SOCKET& listenSocket, SOCKET& jobSocket, string port);
		
	};
	class MyClientService : public MyService {
	public:
		string host;
		string port;
		MyClientService(string host, string port);
		~MyClientService();
		bool doServe();
		bool doClientJob(SOCKET& jobSocket);
		int firstNum;//JOB LINE
		int secondNum;//JOB LINE
		int sumOfNumbers;//JOB LINE
		void doJobStepOne(SOCKET& jobSocket);
		void doJobStepTwo(SOCKET& jobSocket);
		void doJobStepThree(SOCKET& jobSocket);
	};
	class MyServerService : public MyService {
	public:
		string port;
		MyServerService(string port);
		~MyServerService();
		bool doServe();
		bool doServerJob(SOCKET& jobSocket);
		int firstNum;//JOB LINE
		int secondNum;//JOB LINE
		int sumOfNumbers;//JOB LINE
		void doJobStepOne(SOCKET& jobSocket);
		void doJobStepTwo(SOCKET& jobSocket);
		void doJobStepThree(SOCKET& jobSocket);
	};
	int main();
}

