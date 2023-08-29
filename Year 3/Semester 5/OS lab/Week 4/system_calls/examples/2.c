#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("PID of process is: %d\n", getpid());
    printf("PPID of process is: %d\n", getppid());
    printf("Before exec of fork\n");
    fork();

    printf("After fork 1: Hello\n");
    fork();

    printf("After fork 2: Greetings\n");
    fork();

    printf("Last fork exec\n");
    return 0;
}
