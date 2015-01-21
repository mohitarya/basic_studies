#include <stdio.h>
#include <signal.h>

void sig_handler(int sig)
{
	printf("Signal Caught Signal = %d\n", sig);
	(void) signal(SIGINT, SIG_DFL);
}

int main()
{
	(void) signal(SIGINT, sig_handler);
	while(1) {
		printf("Waiting for signal\n");
		sleep(1);
	}
	return 0;
}
