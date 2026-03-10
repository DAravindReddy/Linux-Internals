#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;
    char buf[100] = "Hello World!";
    char buf2[100];

    /* Open first file */
    fd1 = open("test.txt", O_WRONLY | O_TRUNC);
    if (fd1 < 0)
    {
        perror("open failed for test.txt");
        return 1;
    }

    /* Open second file */
    fd2 = open("test1.txt", O_WRONLY | O_TRUNC);
    if (fd2 < 0)
    {
        perror("open failed for test1.txt");
        return 1;
    }

    /* Write to test1.txt */
    ssize_t ret = write(fd2, buf, strlen(buf) + 1);
    printf("ret -> %ld\n", ret);

    /* Copy buffer */
    strcpy(buf2, buf);

    /* Write to test.txt */
    ssize_t ret2 = write(fd1, buf2, strlen(buf2) + 1);
    printf("ret2 -> %ld\n", ret2);

    /* Close files */
    close(fd1);
    close(fd2);

    return 0;
}
