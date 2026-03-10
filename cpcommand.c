#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int src, dest;
    char buf[1024];
    ssize_t bytes;
    struct stat st;

    if (argc < 3)
    {
        printf("Usage:\n");
        printf("./a.out src dest\n");
        printf("./a.out -p src dest\n");
        return -1;
    }

    int preserve = 0;
    char *srcfile;
    char *destfile;

    if (argc == 4 && strcmp(argv[1], "-p") == 0)
    {
        preserve = 1;
        srcfile = argv[2];
        destfile = argv[3];
    }
    else
    {
        srcfile = argv[1];
        destfile = argv[2];
    }

    src = open(srcfile, O_RDONLY);
    if (src == -1)
    {
        perror("open source");
        return -1;
    }

    dest = open(destfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest == -1)
    {
        perror("open dest");
        close(src);
        return -1;
    }

    while ((bytes = read(src, buf, sizeof(buf))) > 0)
    {
        write(dest, buf, bytes);
    }

    if (preserve)
    {
        stat(srcfile, &st);
        chmod(destfile, st.st_mode);
    }

    close(src);
    close(dest);

    printf("File copied successfully\n");

    return 0;
}
