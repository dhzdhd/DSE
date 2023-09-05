#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Current process id: %d\n", getpid());
    pid_t child_pid = fork(); // Create child

    printf("Hi\n");

    if (child_pid > 0)
    {
        wait(NULL);
        printf("Child complete\n");
    }

    printf("Bye\n");

    return 0;
}

// Current process id: 27672
// Hi
// Hi
// Bye
// Child complete
// Bye
