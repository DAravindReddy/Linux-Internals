
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	//system = fork + exec
        int x = system("ls -l");
        printf("%d\n", x);
        return 0;

}

