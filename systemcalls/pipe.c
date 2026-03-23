#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int fd[2];
    char buf[20];

    pipe(fd);

    if(fork() == 0)
    {
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
    }
    else
    {
        char msg[] = "Hello Child";
        write(fd[1], msg, strlen(msg)+1);
    }

    return 0;
}
