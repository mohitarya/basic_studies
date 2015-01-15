/*This program will create an thread and shows that it sharing the 
 *varible from the orignal process.
 * */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char msg[] = "Hello...I am thread1";

void *thread1_fun(void *);

int main()
{
	int ret_val;
	char *thread_ret;
	void *thread_result;
	pthread_t thread1;
	ret_val = pthread_create(&thread1, NULL, thread1_fun, (void *)msg);
	if (ret_val != 0) {
		printf("Error in creating the thread\n");
		exit(-1);
	}
	printf("Waiting for thread for finish...\n");
	ret_val = pthread_join(thread1, &thread_result);
	if (ret_val != 0) {
		printf("Thread Joining Failed\n");
		exit(-1);
	}
	printf("Thread joining successfull and it returned %s\n", (char *)thread_result);
	printf("Now msg = %s\n", (char *)msg);
}

void *thread1_fun(void *msg)
{
	printf("In Function thread1_fun()\n");
	printf("msg = %s\n", (char *)msg);
	strcpy(msg, "....Byeeee....");
	pthread_exit("....Yeepeee....");
}
