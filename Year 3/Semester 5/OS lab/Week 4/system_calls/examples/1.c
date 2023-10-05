#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("PID of process is: %d\n", getpid());
    printf("PPID of process is: %d\n", getppid());

    return 0;
}

// PID of process is: 27202
// PPID of process is: 1756
