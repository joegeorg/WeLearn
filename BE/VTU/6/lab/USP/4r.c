#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#define MAX_BUF 1024
int main(int argc, char **argv)
{
	int fd;
	char buf[MAX_BUF];
	fd=open(argv[1],O_RDONLY);
	read(fd,buf,MAX_BUF);
	printf("Recieved:%s",buf);
	close(fd);
	return 0;
}
