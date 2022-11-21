#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

void main(void)
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	fork();
	pid = getpid();

	for (i = 1; i <= MAX_COUNT; i++) {
		sprintf(buf, "PID = %d, valor = %d\n", pid, i);
		write(1, buf, strlen(buf));
	}
	exit(0);
}
