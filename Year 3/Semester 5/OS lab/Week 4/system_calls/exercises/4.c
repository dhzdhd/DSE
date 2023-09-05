#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork(); // Create child

    if (pid > 0)
    {
        printf("In parent process\n");
    }
    else if (pid == 0) // Child process
    {
        printf("In child process\n");
        printf("Child's parent PID before becoming orphan: %d\n", getppid());
        sleep(5); // Sleep to make the child an orphan
        printf("Child's parent PID after becoming orphan: %d\n", getppid());
    }

    return 0;
}

// In parent process
// In child process
// Child's parent PID before becoming orphan: 11
// (base) [deep@deep exercises]$ Child's parent PID after becoming orphan: 11
