#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PIPE_FAILURE 1

int main()
{
	int pipe_fd[2], ret_val, bytes=0;
	char write_data[] = "Hi India is Great";
	char read_data[BUFSIZ + 1];
	//Low level pipe call. This pipe call will written to FD.
	//pipe_fd[1] for writting the data and pipe_fd[2] for reading
	//the written data to pipe_fd[1]
	ret_val = pipe(pipe_fd);
	if (ret_val != 0) {
		perror("Pipe Creation Error");
		exit(PIPE_FAILURE);
	}
	ret_val = fork();
	if (ret_val == -1) {
		perror("Fork() Error");
	}
	else if (ret_val == 0) {
		bytes = read(pipe_fd[0], read_data, BUFSIZ);
		printf("Read Bytes = %d\n%s\n", bytes ,read_data);
	}
	else {
		bytes = write(pipe_fd[1], write_data, sizeof(write_data));
		printf("Write Bytes = %d\n%s\n", bytes ,write_data);
		wait();
	}
	return 0; 
}
