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
	struct msgbuff recv_strc;
	char buffer[BUFSIZ];
	//Get a system V msg queue identifier
	msgqueid = msgget(msgid, IPC_CREAT);
	if (msgqueid == -1) {
		perror("Error in getting msg queue");
		exit(EXIT_FAILURE);
	}
	while(running) {
		//Sending the msg to the other process
		ret_val = msgrcv(msgqueid, (void *) &recv_strc, (size_t) sizeof(recv_strc.mtxt), 0, 0);
		if (ret_val == -1) {
			perror("Error in msg receiving");
			exit(EXIT_FAILURE);
		}
		printf("Recieved Msg = %s", (char *)recv_strc.mtxt);
		if (strncmp(recv_strc.mtxt, "end", 3) == 0) {
			running = 0;
		}
	}
	//Deleting the msg queue
	ret_val = msgctl(msgqueid, IPC_RMID, NULL);
	if (ret_val == -1) {
		perror("Error in deleting the msg queue");
	        exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
