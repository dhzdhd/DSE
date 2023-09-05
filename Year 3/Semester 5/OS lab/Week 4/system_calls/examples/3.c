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

    printf("Child process id is: %d\t", pid);  // Return pid
    printf("Child process parent ID is: %d\t", getppid());
    printf("Greetings!\n");

    return 0;
}

// PID of process is: 27407
// PPID of process is: 1756
// Child process id is: 27407      Child process parent ID is: 1756        Greetings!
// Child process id is: 27408      Child process parent ID is: 27407       Greetings!
