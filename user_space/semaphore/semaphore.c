#include <stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_fun(void *);

int shared_data;
sem_t sem;

int main()
{
	int ret_val;
	pthread_t thread_id;
	//Initialization of the semaphore	
	ret_val = sem_init(&sem, 0, 0);
	if (ret_val == -1) {
		perror("Semaphore initialization Error");
		exit(EXIT_FAILURE);
	}
	//Creation of the thread
	ret_val = pthread_create(&thread_id, NULL, thread_fun, NULL);
	if (ret_val == -1) {
		perror("Thread Creation Error");
		exit(EXIT_FAILURE);
	}
	//Input data for the shared resource from user
	printf("Input a number to the shared data\n");
	scanf("%d", &shared_data);
	//Increament the semaphore variable value
	sem_post(&sem);
	printf("Waiting for thread to finish\n");
	ret_val = pthread_join(thread_id, NULL);
	if (ret_val != 0) {
		perror("Error in joining the thread");
		exit(EXIT_FAILURE);
	}
	printf("Thread Joined Successfully\n");
	ret_val = sem_destroy(&sem);
	if (ret_val != 0) {
		perror("Error in semaphore destruction");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
//Thread function
void *thread_fun(void *arg) {
	sem_wait(&sem);
	printf("Your Input data = %d\n", shared_data);
	pthread_exit(NULL);
}
