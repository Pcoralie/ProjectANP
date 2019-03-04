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
	// Connect to a server 
	struct sockaddr_in server;

	
	printf("\nInitialising Winsock..."); 
	if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
	{		
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n"); 
	
	// create a socket 
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
		return 1;
	}
	printf("Socket created.\n");
	
	server.sin_addr.s_addr = inet_addr("172.217.17.35"); //google.fr
	server.sin_family = AF_INET; // The Internet Protocol version 4 (IPv4)
	server.sin_port = htons( 80 ); // it would be a good idea to read Course Port Number
	//Connect to remote server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	puts("Connected");

	while (getchar() != '\n') ;
	return 0; 
}

/*
struct sockaddr_in {
short sin_family; // e.g. AF_INET, AF_INET6
unsigned short sin_port; // e.g. htons(3490)
struct in_addr sin_addr; // see struct in_addr, below
char sin_zero[8]; // zero this if you want to
};

typedef struct in_addr {
union {
struct {
u_char s_b1,s_b2,s_b3,s_b4; //unsigned char
} S_un_b;

struct {
u_short s_w1,s_w2;
} S_un_w;
u_long S_addr;
} S_un;
} IN_ADDR, *PIN_ADDR, FAR *LPIN_ADDR;
struct sockaddr {
unsigned short sa_family; // address family, AF_xxx
char sa_data[14]; // 14 bytes of protocol address
}; 

*/ 