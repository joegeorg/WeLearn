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
	int i=0;
	char ch;
	mknod(FIFO1_NAME,S_IFIFO|0666,0);
	mknod(FIFO2_NAME,S_IFIFO|0666,0);
	printf("\nServer online\n");
	fd=open(FIFO1_NAME,O_RDONLY);
	printf("\nClient online. \n Waiting for the request \n");
	while(1)
	{
		if((num=read(fd,p,3000))==-1)
			perror("Read error!!!\n");
		else
		{
			p[num]='\0';
			if((f1=open(p,O_RDONLY))<0)
			{
				printf("\nServer:%s not found...\n",p);
				exit(1);
			}
			else
			{
				printf("\nServer:%s found \n transfering contents...\n",p);
				stdin=fdopen(f1,"r");
				i=0;
				while(1)
				{
					ch=fgetc(stdin);
					if(ch==EOF)
						break;
					else
						c[i++]=ch;
				}
				fd2=open(FIFO2_NAME,O_WRONLY);
				if(num2=write(fd2,c,strlen(c))==-1)
					perror("\nTransfer error !\n");
				else
					printf("\nServer : Transfer completed\n");
				exit(1);
			}
		}
	}
	return 1;
}
