#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TXT_SIZE 2048

int main()
{
	struct msgbuff {
		long mtype;
		char mtxt[TXT_SIZE];
	};
	int ret_val, msgid=1234, running =1;
	int msgqueid;
	struct msgbuff send_strc;
	char buffer[BUFSIZ];
	//Get a system V msg queue identifier
	msgqueid = msgget(msgid, IPC_CREAT);
	if (msgqueid == -1) {
		perror("Error in getting msg queue");
		exit(EXIT_FAILURE);
	}
	send_strc.mtype = 1;
	while(running) {
		printf("Input msg to send\n");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(send_strc.mtxt, buffer, TXT_SIZE);
		//Sending the msg to the other process
		ret_val = msgsnd(msgqueid, (const void *) &send_strc, (size_t) sizeof(send_strc.mtxt), 0);
		if (ret_val != 0) {
			perror("Error in msg sending");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "end", 3) == 0) {
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
}
