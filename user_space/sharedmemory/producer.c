#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm.h"

int main()
{
        int ret_val, shm_id, running=1;
        struct shared_data_st *shared_data;
        void *shared_mem_add = NULL;
	char buffer[BUFSIZ];
        //Allocates a system shared memory segment
        shm_id = shmget((key_t)1234, sizeof(shared_data), IPC_CREAT);
        if (shm_id == -1) {
                perror("Shared memory creation error");
                exit(EXIT_FAILURE);
        }
        //Attach the shared memory segment with the current process
        shared_mem_add = shmat(shm_id, NULL, 0);
        if (shared_mem_add == NULL) {
                perror("Attach failed of shared memory with the process");
                exit(EXIT_FAILURE);
        }
        shared_data = (struct shared_data_st *)shared_mem_add;
        while(running) {
		while (shared_data->data_written == 1) {
			printf("waiting for consumer to read\n");
			sleep(1);
		}
		printf("Input the data and write end to finsh the writting\n");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(shared_data->some_txt, buffer, TXT_SIZE);
		shared_data->data_written = 1;
		if(strncmp(buffer, "end", 3) == 0) {
			running = 0;
		}
	}

        //Detaching the shared memory and then delete
        ret_val = shmdt(shared_mem_add);
        if(ret_val != 0) {
    		perror("Detaching the shared memory fail");
                exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
}

