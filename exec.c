
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>


int main()
{
	printf("Executing ls using exec()\n");

	execl("/bin/ls", "ls", (char *)NULL);






}
