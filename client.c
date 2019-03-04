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
	
	printf("\nInitialising Winsock..."); 
	if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
	{		
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised."); 
	
	return 0; 
}