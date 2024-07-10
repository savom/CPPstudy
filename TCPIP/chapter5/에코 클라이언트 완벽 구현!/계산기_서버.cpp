#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4

void ErrorHandling(char* message);

int calculate(int opnum, int opnds[], char oprater);

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServScok, hClntSock;
	char opinfo[BUF_SIZE];
	int result, opndcnt, i;
	int recvCnt, recvLen;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSize;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	hServScok = socket(PF_INET, SOCK_STREAM, 0);
	if (hServScok == INVALID_SOCKET)
		ErrorHandling("socket() error!");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServScok, (SOCKADDR*)*servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	if (listen(hServScok, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");
	clntAdrSize = sizeof(clntAdr);

	for (i = 0; i < 5; i++)
	{
		opndcnt = 0;
		hClntSock = accept(hServScok, (SOCKADDR*)&clntAdr, &clntAdrSize);

	}

}