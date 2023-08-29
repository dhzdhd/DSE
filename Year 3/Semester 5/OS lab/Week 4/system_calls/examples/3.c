#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int pid;
    printf("PID of process is: %d\n", getpid());
    printf("PPID of process is: %d\n", getppid());
    fork();

    pid = getpid();

    printf("Child process id is: %d\t", pid);
    printf("Child process parent ID is: %d\t", getppid());
    printf("Greetings!\n");

    return 0;
}
