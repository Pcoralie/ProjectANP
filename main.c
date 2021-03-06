#ifdef WIN32
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


static void help(void)
{
	printf( 
	"CLIENT COMMANDS:\n"
						"/exit           \n"	
                        "/help          Lists all client commands. The thing you just typed in.\n"
                        "/listu         Lists all clients connected to server.\n"
                        "/listf         Lists all files in a server.\n"
						"/trfu          Transfert Upload file in a server.\n"
						"/trfd          Transfert Download file in a server.\n"
						"/private <user  Commute to private.\n"
						"/public         Commute to public.\n"
						"/ring <user>    Notification if user is connect.\n"
						"/time          Displays how long the client has been connected to server.\n"); 
}

static void init(void)
{
	printf("\nInitialising Winsock...");
#ifdef WIN32
    WSADATA wsa;

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		//return 1;
		exit(EXIT_FAILURE); 
	}
	printf("Initialised.\n");
	
#endif
}

static void end(void)
{
#ifdef WIN32
    WSACleanup();
#endif
}




int main(int argc , char *argv[])
{
		init(); 
	SOCKET s, new_socket;
	struct sockaddr_in server, client;
	int c; 
	char* client_ip = inet_ntoa(client.sin_addr); 
	int client_port = ntohs(client.sin_port); 
	char* message; 

	
	
	// create a socket 

	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
		return 1;
	}
	printf("Socket created.\n");
	
	/*
	 * Address Family : AF_INET (this is IP version 4)
Type : SOCK_STREAM (this means connection oriented TCP protocol)
Protocol : 0 [ or IPPROTO_TCP , IPPROTO_UDP ]
 * */
 
	
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET; // The Internet Protocol version 4 (IPv4)
	server.sin_addr.s_addr = INADDR_ANY;
	//server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	server.sin_port = htons( 8888 ); // port number
	
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
	
	c = sizeof(struct sockaddr_in);
	
	//new_socket = accept(s , (struct sockaddr *)&client, &c);
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
	

	 
	closesocket(s); // SOCKET s; for our program sample
	end(); 

 
	//while (getchar() != '\n') ;
	printf("\nPress Any Key to Continue\n");  
	getchar();   
	return 0;
	

}

/*
// IPv4 AF_INET sockets:
struct sockaddr_in {
	short sin_family; // e.g. AF_INET, AF_INET6
	unsigned short sin_port; // e.g. htons(3490)
	struct in_addr sin_addr; // see struct in_addr, below
	char sin_zero[8]; // zero this if you want to
};
 * 
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

/* Description of data base entry for a single host. */
/*
struct hostent
{
char *h_name; // Official name of host. 
char **h_aliases; // Alias list. 
int h_addrtype; // Host address type. 
int h_length; // Length of address. 
char **h_addr_list; // List of addresses from name server. 
};*/