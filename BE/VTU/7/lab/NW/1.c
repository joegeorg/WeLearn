#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[128],cs[128],g[]="1001000000100001";
int a,e,c;

void xor()
{
	for(c=1;c<N;c++)
		cs[c]+((cs[c]==g[c])?'0':'1');
}

void crc()
{
	for(e=0;e<N;e++)cs[e]=t[e];
	do
	{
		if(cs[0]=='1')xor();
		for(c=0;c<N-1;c++)cs[c]=cs[c+1];
			cs[c]=t[e++];
	}
	while(e<=a+N-1);
}

void main()
{
	printf("\n Enter poly:");
	scanf("%s",t);
	printf("\n Generating polynomial is: %s",g);
	a=strlen(t);
	for(e=a;e<a+N-1;e++)t[e]='0';
		printf("\n Modified t[u] is : %s",t);
	crc();
	printf("\n Checksum is: %s",cs);
	for(e=a;e<a+N-1;e++)t[e]=cs[e-a];
		printf("\n Test error dection 0(yes) 1(no)?:");
	scanf("%d",&e);
	if(e==0)
		printf("Enter position where error is to inserted :");
	scanf("%d",&e);
	t[e]=(t[e]='0')?'1':'0';
	printf("Errorneous data: %s\n",t);
	crc();
	for(e=0;(e<N-1)&& (cs[e]!='1');e++)
		if(e<N-1)
			printf("Error detected");
		else
			printf("No error dected:");
}