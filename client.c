#ifdef WIN32

#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#include <windef.h>
#include <winsock2.h>
typedef int socklen_t;

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include<io.h>



int main(int argc, char *argv[])
{
#ifdef WIN32
	WSADATA wsa;
#endif

	SOCKET s;
	SOCKET new_socket;

	// Connect to a server
	struct sockaddr_in server, client;
	int c; 

	char* client_ip = inet_ntoa(client.sin_addr);
	int client_port = ntohs(client.sin_port);
	char* message;




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
#ifdef WIN32
		printf("Could not create socket : %d" , WSAGetLastError());
#endif
		return 1;
	}
	printf("Socket created.\n");


//	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // or localhost to test
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET; // The Internet Protocol version 4 (IPv4)
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	puts("Connected");

	//Bind
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d" , WSAGetLastError());
	}
	puts("Bind done");

	//Listen to incoming connections
	listen(s , 3);

	// Accept and incoming connection
	puts("Waiting for incoming connections...");

	c = sizeof(struct sockaddr_in);	//new_socket = accept(s , (struct sockaddr *)&client, &c);
	/*
	if (new_socket == INVALID_SOCKET)
	{
		printf("accept failed with error code : %d" , WSAGetLastError());
	}
	puts("Connection accepted");

	//Reply to client
	message = "Hello Client , I have received your connection. BYE \n";
	send(new_socket , message , strlen(message) , 0);
	getchar();
	*/

	// server running non stop
	while( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
	{
		puts("Connection accepted");

		//Reply to the client
		message = "Hello Client , I have received your connection. \n";
		send(new_socket , message , strlen(message) , 0);
	}

	/*
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



	 if ( (he = gethostbyname( hostname ) ) == NULL)
	{
		//gethostbyname failed
		printf("gethostbyname failed : %d" , WSAGetLastError());
		return 1;
	}

	//Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
	addr_list = (struct in_addr **) he->h_addr_list;

	for(i = 0; addr_list[i] != NULL; i++)
	{
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}
	printf("%s resolved to : %s\n" , hostname , ip);
	 */

	closesocket(s); // SOCKET s; for our program sample
	WSACleanup();


	//while (getchar() != '\n') ;
	printf("\nPress Any Key to Continue\n");
	getchar();
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
