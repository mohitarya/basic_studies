/*
 *This program create a server for the socket programming study 
 *It can serve to the multiple clients and send and receive data from them
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define SOCK_SUCCESS 0
#define SOCK_FAILURE 1
#define PORT_NUM 900
#define BUFF_SIZE 1024

int main()
{
	int server_fd, client_fd, server_addr_len, client_addr_len, ret_val;
	struct sockaddr_in server_addr, client_addr;
	char read_buff[BUFF_SIZE];
	char write_buff[BUFF_SIZE];
	memset(read_buff, 0x00, sizeof(read_buff));
	memset(write_buff, 0x00, sizeof(write_buff));
	strcpy(write_buff, "I am Server");
	// socket() API is used to create a socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		printf("Error in creating the socket\n");
		exit(SOCK_FAILURE);
	}
	// bind a name to the socket. socket() API  just create a socket in 
	// the name space but address is not assigned to it. bind() API assigned 
	// address to the socket craeted by socket API.
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htonl(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr_len = sizeof(server_addr);
	ret_val = bind(server_fd, (const struct sockaddr *) &server_addr, (socklen_t) server_addr_len);
	if (ret_val != 0) {
		printf("Error in binding the socket\n");
		exit(SOCK_FAILURE);
	}
	//listen for a connection on the socket
	ret_val = listen(server_fd, 10);
	if (ret_val != 0) {
		printf("Error in listening to the socket\n");
		exit(SOCK_FAILURE);
	}
	//Accept a connection on the socket
	printf("Waiting for client to connect...\n");
	client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
	if (client_fd == -1) {
		printf("Error in accepting socket call from client\n");
		exit(SOCK_FAILURE);
	}
	//Writing and reading from the client file discriptor
	while(1) {
		read(client_fd, read_buff, sizeof(read_buff));
		printf("%s\n", read_buff);
		sleep(1);
		write(client_fd, read_buff, sizeof(write_buff));
		sleep(1);
	}
	return SOCK_SUCCESS;
}
