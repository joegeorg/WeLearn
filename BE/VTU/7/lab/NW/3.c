#include<stdio.h>
#include <stdlib.h>
int p[10][10];
void path(int i, int j)
{
int k;
k= p[i][j];
if (k!=0)
{
path(i,k);
printf("%d -->",k);
path(k,j);
}}
int main()
{
int a[10][10],i,j,k,n,ch;
printf("enter the no of nodes: ");
scanf("%d",&n);
printf("enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
p[i][j]=0;
}}
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(a[i][k]+a[k][j]<a[i][j])
{
a[i][j]=a[i][k]+a[k][j];
p[i][j]=k;
}}
printf("\nshortest path between the nodes: ");
for (i=1;i<=n;i++)
{
printf("\nrouting table for node %d",i);
printf("\nto-node distance next hop \n");
for(j=1;j<=n;j++)
printf("%d \t %d \t %d \n",j,a[i][j],p[i][j]);
}
do
{
printf("\nenter the source and destination :\n");
scanf("%d %d",&i,&j);
printf("weight is %d", a[i][j]);
printf("\npath is");
printf("\n%d -->",i);
path (i,j);
printf("%d",j);
printf("\nto repeat ,press 1\n");
scanf("%d",&ch);
}
while(ch==1);
return 0;
}

