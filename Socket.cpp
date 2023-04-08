#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#define port 3000
// #pragma comment (lib,"ws2_32.lib")
using namespace std;
#endif

class Server {
private:
	SOCKET clientSocket;// socket de nhan va ket noi voi client.
	sockaddr_in hint;
	string IPaddress;
	int serverPort;
	char buffer[1024] = { '\0' };

public:

	Server(string IP, int portnumber) {
		this->IPaddress = IP;
		this->serverPort = portnumber;
	}

	bool initSocket() {
        int result = 0;
        try {
            WSADATA hextech;
		    WORD version = MAKEWORD(2, 2);
		    result = WSAStartup(version, &hextech);
        } catch (exception ex){
            cout << ex.what();
        }
		
		if (result != 0) {
			cout << "Error: can't start Winsock." << endl;
			return false;
		}
		return true;
	}

	void CreateSocket() {
		int i = 1;
		clientSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (clientSocket != INVALID_SOCKET) {

			setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&i, sizeof(i));

			hint.sin_family = AF_INET;
			hint.sin_port = htons(this->serverPort);
			hint.sin_addr.s_addr = inet_addr(this->IPaddress.c_str());
		
			int bindCheck = bind(clientSocket, (struct sockaddr*)&hint, sizeof(hint));
			if (bindCheck != SOCKET_ERROR) {//If bind OK:

				int listenCheck = listen(clientSocket, SOMAXCONN);	//Tell the socket is for listening. 
				unsigned long b = 1;
				ioctlsocket(clientSocket, FIONBIO, &b);

				if (listenCheck == SOCKET_ERROR) {
					cerr << "Can't listen from client.\n";
					closesocket(clientSocket);
					WSACleanup();
					exit(-1);
				}
			}
			else {
				cerr << "Can't bind the socket.\n";
				closesocket(clientSocket);
				WSACleanup();
				exit(-1);
			}

		}
		else {
			cout << "Error: can't create socket in server." << endl;
			closesocket(clientSocket);
			WSACleanup();
			exit(-1);
		}

	}

    void Start(){
		CreateSocket();
		cout << "Server is runing ... " << endl;
		while (true) {
            int count =0;
			int len = sizeof(hint);
			SOCKET connectionline = accept(clientSocket, (sockaddr*)&hint, &len);

			if (connectionline != INVALID_SOCKET){
                count+=1;
				cout << "New client: " << connectionline << endl;
				cout << "Number of client: " << count << endl; 
			}

			Sleep(1);
        }
    }

	string ReceiveFrom(SOCKET sock_id) {
		ZeroMemory(buffer, 1024);
		if (recv(sock_id, buffer, 1024, 0) < 0) {
			return "";
		}
		string response = string(buffer);
		return response;
	}

	void SendTo(SOCKET sock_id, string package) {
		send(sock_id, package.c_str(), package.size(), 0);
	}

	~Server() {
		closesocket(clientSocket);
		WSACleanup();
	}
};

class Client {
private:
	string IPaddress;
	int clientPort;
	sockaddr_in hint;
	SOCKET serverSocket;

public:

	Client() {
		clientPort = 0;
		IPaddress = "";
	}

	Client(string ip, int paraPort)
	{
		IPaddress = ip;
		clientPort = paraPort;
	}

	void setServerIP(string ip)
	{
		this->IPaddress = ip;
	}

	void setPortNumber(int paraPort)
	{
		this->clientPort = paraPort;
	}

	bool initSocket() {
		WSADATA hextech;
		WORD version = MAKEWORD(2, 2);
		int result = WSAStartup(version, &hextech);
		if (result != 0) {
			cout << "Error: can't start Winsock." << endl;
			return false;
		}
		return true;
	}

	void CreateSocket() {
		serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (serverSocket == INVALID_SOCKET) {
			cout << "Error: can't create socket." << endl;
			WSACleanup();
			exit(-1);
		}

		hint.sin_family = AF_INET;
		hint.sin_port = htons(this->clientPort);
		hint.sin_addr.s_addr = inet_addr(this->IPaddress.c_str());
		// inet_pton(AF_INET, IPaddress.c_str(), &hint.sin_addr);
	}

	void ConnectSocket() {
		CreateSocket();
		int connResult = connect(serverSocket, (sockaddr*)&hint, sizeof(hint));

		if (connResult == SOCKET_ERROR) {
			cout << "Error: can't connect to server." << endl;
			closesocket(serverSocket);
			WSACleanup();
			exit(-1);
		}
		else{
			cout << "Connected to Server.\n";
		}
	}


	void Sending(string text) {
		if (!text.empty() && serverSocket != INVALID_SOCKET)
		{
			int result = send(serverSocket, text.c_str(), text.size() + 1, 0);

			if (result == SOCKET_ERROR) {
				cout << "send fail with error: " << WSAGetLastError() << endl;
				closesocket(serverSocket);
				WSACleanup();
				exit(1);
			}
		}

	}

	string Receive() {
		char buffer[1024] = {};
		string reply;
		if (recv(serverSocket, buffer, 1024, 0) < 0)
			return "";
		reply = string(buffer);
		return reply;
	}

	SOCKET Socket() {
		return this->serverSocket;
	}

	~Client() {
		Sending("Disconnect");
		closesocket(serverSocket);
		WSACleanup();
	}
};
