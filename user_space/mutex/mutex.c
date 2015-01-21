#include <stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_fun(void *);

int shared_data;
pthread_mutex_t mutex_lock;

int main()
{
	int ret_val;
	pthread_t thread_id;
	//Initialization of the semaphore	
	ret_val = pthread_mutex_init(&mutex_lock, NULL);
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
	//Lock the mutex
	pthread_mutex_lock(&mutex_lock);
	printf("Input a number to the shared data\n");
	scanf("%d", &shared_data);
	//Unloak the mutex
	pthread_mutex_unlock(&mutex_lock);
	printf("Waiting for thread to finish\n");
	ret_val = pthread_join(thread_id, NULL);
	if (ret_val != 0) {
		perror("Error in joining the thread");
		exit(EXIT_FAILURE);
	}
	printf("Thread Joined Successfully\n");
	ret_val = pthread_mutex_destroy(&mutex_lock);
	if (ret_val != 0) {
		perror("Error in semaphore destruction");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
//Thread function
void *thread_fun(void *arg) {
	pthread_mutex_lock(&mutex_lock);
	printf("Your Input data = %d\n", shared_data);
	pthread_mutex_unlock(&mutex_lock);
	pthread_exit(NULL);
}
