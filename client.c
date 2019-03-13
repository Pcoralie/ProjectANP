//#ifdef WIN32

#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#include <windef.h>
#include <winsock2.h>
typedef int socklen_t;


/*
#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // close 

#include <netdb.h> // gethostbyname 
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
#ifdef WIN32
	WSADATA wsa;
#endif

	SOCKET s;
	// Connect to a server
	struct sockaddr_in server;
	char * message , server_reply[2000];
	int recv_size;


	printf("\nInitialising Winsock...");
#ifdef WIN32
	if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
#endif

	printf("Initialised.\n");

	// create a socket
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
		return 1;
	}
	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr("172.217.17.35"); //google.fr
	server.sin_addr.s_addr = inet_addr("205.178.189.131"); //bourse.com
	server.sin_family = AF_INET; // The Internet Protocol version 4 (IPv4)
	server.sin_port = htons( 80 ); // it would be a good idea to read Course Port Number
	
	//Connect to remote server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	puts("Connected");
	
	//Send some data
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(s , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
	
	//Receive a reply from the server
	if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
	{
		puts("recv failed");
	}
	puts("Reply received\n");

	//Add a NULL terminating character to make it a proper string before printing
	server_reply[recv_size] = '\0';
	puts(server_reply);
	
	//Bind
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d" , WSAGetLastError());
	}
	puts("Bind done");
	
		
	closesocket(s); // SOCKET s; for our program sample
	WSACleanup();

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
