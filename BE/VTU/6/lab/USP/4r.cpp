#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
using namespace std;
 #define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
 int pipe_fd,res=0;
 char buffer[BUFFER_SIZE + 1];
 if(argc!=2)
 {
   cout<<"usage:./a.out pipe_name\n";
   return -1;
 }
 cout<<"Opening fifo in read mode"<<endl;
 if((pipe_fd=open(argv[1],O_WRONLY))!=1)
 {
  res=read(pipe_fd,buffer,BUFFER_SIZE);
  cout<<buffer;
  close(pipe_fd);
}
else
  perror("\n Fifo error");
cout<<"\nprocess "<<getpid()<<" finished reading\n"<<endl;
return 0;
}