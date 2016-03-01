
#include<stdio.h>
#include<stdlib.h>
int main()
{
int i;
char **ptr;
extern char **environ;
printf("List of Environmental Variable\n");
printf("--------------------------------\n");
for (ptr = environ; *ptr != 0; ptr++) 
printf("%s\n", *ptr);
exit(0);

}