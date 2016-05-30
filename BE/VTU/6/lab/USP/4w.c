#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define MAX_BUF 1024
int main(int argc, char **argv)
{
	int fd;
	char message[MAX_BUF+1];
	printf("Enter the message !\n");
	gets(message);
	mkfifo(argv[1],0666);
	fd=open(argv[1],O_WRONLY);
	write(fd,message,MAX_BUF);
	close(fd);
	return 0;
}
