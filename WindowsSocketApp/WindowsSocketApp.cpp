#include <iostream>
#include <winsock.h>
#define PORT 990
using namespace std;

struct sockaddr_in srv;
fd_set  fr, fw, fe;
int nMaxFd;

int main()
{
	int nRet = 0;

	//Initialize WSA variables
	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws))
	{
		cout << endl << "WSA Failed to initialize";
	}
	else
	{
		cout << endl << "WSA successfully";
	}
	//Initialize the socket
	int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (nSocket < 0)
	{
		cout << endl << "The socket is not open";
	}
	else
	{
		cout << endl << "Opened successfully" << nSocket;
	}
	
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORT);
	srv.sin_addr.s_addr = INADDR_ANY;
	memset(srv.sin_zero, 0, 8);

	nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));
	if (nRet < 0)
	{
		cout << "Failed to bind to local port" << endl;
	}
	else
	{
		cout << "connected successfully" << endl;
	}

	nRet = listen(nSocket, 5);
	if (nRet < 0)
	{
		cout << "Failed to start listen to local port" << endl;
	}
	else
	{
		cout << "started listening to local port" << endl;
	}
	int n = 100;
	for (int nIndex = 0; nIndex < 64; nIndex++)
	{
		FD_SET(n, &fr);
		n++;
	}

	cout << endl << fr.fd_count << endl;

	for (int nIndex = 0; nIndex < 64; nIndex++)
	{
		cout << fr.fd_array[nIndex] << "\t";
	}

	nMaxFd = nSocket;


}
