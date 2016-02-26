#include<stdio.h>

main()
{
    char cmd[10];
    int ch;
    int pid;
    pid=fork();
    if(pid==0)
    {
        do
        {
            printf("Enter the command to be executed:\n");
            scanf("%s",cmd);
            system(cmd);
            printf("\n Enter 1 to enter more commands,0 to exit\n");
            scanf("%d",&ch);
        }while(ch!=0);
    }
wait();
}
