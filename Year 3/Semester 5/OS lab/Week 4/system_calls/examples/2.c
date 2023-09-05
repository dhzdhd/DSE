#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("PID of process is: %d\n", getpid());
    printf("PPID of process is: %d\n", getppid()); // Parent pid
    printf("Before exec of fork\n");
    fork();

    printf("After fork 1: Hello\n");
    fork();

    printf("After fork 2: Greetings\n");
    fork();

    printf("Last fork exec\n");
    return 0;
}

// PID of process is: 27313
// PPID of process is: 1756
// Before exec of fork
// After fork 1: Hello
// After fork 1: Hello
// After fork 2: Greetings
// After fork 2: Greetings
// After fork 2: Greetings
// After fork 2: Greetings
// Last fork exec
// Last fork exec
// Last fork exec
// Last fork exec
// Last fork exec
// Last fork exec
// Last fork exec
// Last fork exec
