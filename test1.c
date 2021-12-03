#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define NUMCHILD 3

void f(int signum)
{
	printf("Received a frog!\n");
}

void g(int signum, siginfo_t *info, void *ctxt)
{
	printf("From where? : %d\n", info->si_pid);
	printf("Received a giraffe!\n");
	exit(SIGUSR2);
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = g;
	signal(SIGUSR1, f);
	// signal(SIGUSR2, g);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
	{
		sleep(1);
	}
}