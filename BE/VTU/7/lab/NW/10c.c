#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"
int main()
{
	char p[3000],f[3000],c[3000];
	int num,num2,f1,fd,fd2;
	char *ptr;
	mknod(FIFO1_NAME,S_IFIFO|0666,0);
	mknod(FIFO2_NAME,S_IFIFO|0666,0);
	printf("\nWaiting for the server\n");
	fd=open(FIFO1_NAME,O_WRONLY);
	printf("\nServer online \n client:enterr the path \n");
	while(gets(p),!feof(stdin))
	{
		if((num=write(fd,p,strlen(p)))==-1)
		{
			perror("Write error!!!\n");
			exit(0);
		}
		else
		{
			printf("Waiting for reply...\n");
			fd2=open(FIFO2_NAME,O_RDONLY);
			if((num2=read(fd2,c,3000))==-1)
				perror("\n transfer error\n");
			else
			{
				printf("\nFile received! Displaying the contents: \n");
				if(fputs(c,stdout)==EOF);
				exit(1);
			}
		}
	}
	return 1;
}
