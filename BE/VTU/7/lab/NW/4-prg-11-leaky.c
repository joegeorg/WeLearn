#include<stdio.h>
#include<stdlib.h>
int main()
{
int psz[5],bsz,ort,prm=0,i,r;
for(i=0;i<5;i++)
{
r=rand()%10;
psz[i]=r*6;
}
for(i=0;i<5;i++)
printf("\n enter the packet size[%d]:%d\n",i,psz[i]);
printf("\n enter the output rate/buffer\n:");
scanf("%d %d",&ort,&bsz);
for(i=0;i<5;i++)
{
if((psz[i]+prm)>bsz)
{
printf("bucket size is not enough\n");
}
else
{
prm=prm+psz[i];
printf("\n psize %d\n",psz[i]);
printf("transmission %d\n",prm);
while(1)
{
if(prm)
{
if(prm<ort)
{
printf("\n transmission done\n");
prm=0;
break;
}
else
{
printf("size of packet %d transmitted\n",ort);
prm-=ort;
printf("remaining size:%d",prm);
}
}
else
{
printf("no packets remaining\n");
break;
}
}
}
}
return 0;
}
