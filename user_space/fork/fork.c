/*
 *fork program to print parent and child process
 * */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t child_pid, counter;
	child_pid = fork();
	switch(child_pid) {
		case 0:
			while(counter < 10) {
				sleep(1);
				printf("I am Child\n");
				counter++;
			}
			break;
		case -1:
			printf("Bad Luck...Fork not successfull. Errorno = %d\n", errno);
			break;
		default:
			while(counter < 5) {
				sleep(1);
				printf("I am Parent\n");
				counter++;
			}
			wait(NULL);
			break;
			
	}
	return 0;
}
