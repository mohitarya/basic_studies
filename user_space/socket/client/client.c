#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#define SOCK_SUCCESS 0
#define SOCK_FAILURE 1
#define BUFF_SIZE 1024
#define PORT_NUM 5001

int main()
{
	int client_fd, client_addr_len, ret_val;
	struct sockaddr_in client_addr;
	char read_buff[BUFF_SIZE], write_buff[BUFF_SIZE];
	memset(read_buff, 0x00, sizeof(read_buff));
	memset(write_buff, 0x00, sizeof(write_buff));
	memcpy(write_buff, "I am client", strlen("I am client"));
	//Creating the socket to the client
	client_fd = (AF_INET, SOCK_STREAM, 0);
	if (client_fd == -1) {
		printf("Error in creating the socket\n");
		exit(SOCK_FAILURE);
	}
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htonl(PORT_NUM);
	client_addr.sin_addr.s_addr = inet_addr("192.168.183.128");
	client_addr_len = sizeof(client_addr);
	ret_val = connect(client_fd, (const struct sockaddr *) &client_addr, client_addr_len);
	if (ret_val == -1) {
		printf("Error in connecting to the server\n");
		exit (SOCK_FAILURE);
	}
	while (1) {
		read(client_fd, read_buff, sizeof(read_buff));
		printf("%s\n", read_buff);
		sleep(1);
		write(client_fd, write_buff, sizeof(write_buff));
		sleep(1);
	}
	return SOCK_SUCCESS;
}
