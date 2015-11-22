#include<stdio.h>
main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("********child's process id *****\n");
printf("Child process id = %d \n",getpid());
printf("Parent process id = %d \n",getppid());
}
else
{
wait();
printf("****** parent's process id *******\n");
printf("Parent process id = %d \n",getpid());
printf("Child's process id = %d " ,pid);
}
return 0;
}
