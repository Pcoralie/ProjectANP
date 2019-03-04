#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#include <windef.h>
#include <winsock2.h>
typedef int socklen_t;
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	WSADATA wsa; 
	SOCKET s; 
	
	printf("\nInitialising Winsock..."); 
	if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
	{		
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n"); 
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
		return 1;
	}
	printf("Socket created.\n");
	
	return 0; 
}