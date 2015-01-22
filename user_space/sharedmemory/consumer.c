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
	shared_data->data_written = 0;
	while(running) {
		if(shared_data->data_written) {
			printf("Data Written = %s\n", shared_data->some_txt);
			sleep(2);
			shared_data->data_written = 0;
			if(strncmp(shared_data->some_txt, "end", 3) == 0) {
				running = 0;
			}
		}
	}
	
	//Detaching the shared memory and then delete
	ret_val = shmdt(shared_mem_add);
	if(ret_val != 0) {
		perror("Detaching the shared memory fail");
		exit(EXIT_FAILURE);
	}
	ret_val = shmctl(shm_id, IPC_RMID, 0);
	if (ret_val == -1) {
		perror("Deletion of shared memory fail");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}
