#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0) // Child process
    {
        printf("Child process: \n");
        printf("Process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    }
    else
    {
        printf("Parent process: \n");
        printf("Process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
    }
    return 0;
}

// Parent process:
// Child process:
// Process ID: 27727
// Process ID: 27726
// Parent process ID: 27726
// Child process ID: 27727
