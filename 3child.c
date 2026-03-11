
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    pid_t ret1, ret2, ret3;

    ret1 = fork();

    if (ret1 < 0)
    {
        perror("fork");
        return -1;
    }

    if (ret1 == 0)
    {
        printf("This is child1 process, pid: %d and parent pid: %d\n", getpid(), getppid());
        exit(0);
    }

    ret2 = fork();

    if (ret2 < 0)
    {
        perror("fork");
        return -1;
    }

    if (ret2 == 0)
    {
        printf("This is child2 process, pid: %d and parent pid: %d\n", getpid(), getppid());
        exit(0);
    }

    ret3 = fork();

    if (ret3 < 0)
    {
        perror("fork");
        return -1;
    }

    if (ret3 == 0)
    {
        printf("This is child3 process, pid: %d and parent pid: %d\n", getpid(), getppid());
        exit(0);
    }

    printf("This is parent process, pid: %d and parent pid: %d\n", getpid(), getppid());

    return 0;
}
