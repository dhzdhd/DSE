#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed");
        exit(-1);
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child complete");
        exit(0);
    }

    return 0;
}

// 1.c  2.c  3.c  4.sh  5.c  main
