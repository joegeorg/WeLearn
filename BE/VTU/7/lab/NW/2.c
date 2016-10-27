#include<math.h>
#include<stdio.h>
#include<string.h>
unsigned int inv(unsigned int num,unsigned int phi)
{
unsigned int i=0;
while((num*i)%phi!=1)
++i;
return i;
}
unsigned int encrypt(unsigned int num,unsigned int key,unsigned int n)
{
int result =(int)(fmodl(powl(num,key),n)+0.5);
if (result<0)result+=n;
return (unsigned int)result;
}
int main(void)
{
char msg[100];
unsigned int p;
unsigned int q;
unsigned int i,n,phi,e,d,result;
printf("enter the value of p and q");
scanf("%d%d",&p,&q);
n=p*q;
phi=(p-1)*(q-1);
printf("choose the value of e");
scanf("%d",&e);
d=inv(e,phi);
printf("ENTER THE TEXT IN CAPITAL");
scanf("%s",msg);
unsigned int cyphertext[sizeof (msg)];
printf("p=%u,q=%u,n=%u,phi(n)=%u,e=%u,d=%u,\n",p,q,n,phi,e,d);
printf("\n\t encrypt msg \"%s\" using key (%u,%u)\n",msg,e,n);
for(i=0;i<strlen(msg);++i)
{
cyphertext[i]=encrypt(msg[i]-64,e,n);
printf("\t%c(%2u)-->%c(%2u)\n",msg[i],msg[i]-64,(char)(cyphertext[i]+64),cyphertext[i]);
}
printf("\n\t decrypt cyphertext using key(%u,%u)\n",d,n);
for(i=0;i<strlen(msg);++i)
{
result=encrypt(cyphertext[i],d,n);
printf("\t%c(%2u)-->%c(%2u)\n",(char)(cyphertext[i]+64),cyphertext[i],(char)(result+64),result);
}
return 0;
}

