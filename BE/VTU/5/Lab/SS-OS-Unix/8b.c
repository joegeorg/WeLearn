#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
main()
{
	int fd;
	char buf1[]="abcdefghijklmnopq";
	char buf2[]="ABCDEFGHIJKLMNOPQ";
	fd=creat("textfile",0622);
	if(fd<0)
	{
		printf("file is not created\n");
		exit(0);
	}
	write(fd,buf1,16);
	lseek(fd,48,SEEK_SET);
	write(fd,buf2,16);
}
