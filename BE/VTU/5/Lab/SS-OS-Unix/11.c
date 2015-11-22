#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int fib(int n)
{
	if(n<2)
		return n;
	else
		return(fib(n-1)+fib(n-2));
}
int random_num()
{
	int temp;
	temp=rand();
	temp=temp%24;
	return(temp);
}
int main(int args,char * argv[])
{
	int fibno[100]={0};
	int i,j,temp,n,tid;
	printf("Enter the no range :");
	scanf("%d",&n);
	omp_set_num_threads(2);
	#pragma omp parallel
	 {
		printf("No of threads ; %d\n",omp_get_num_threads());
		#pragma omp for private(tid,temp,fibno)
		for(j=1;j<=n;j++)
		{

			temp=random_num();
			printf("Thread id %d\n",tid);
			#pragma omp critical
			{
				for(i=0;i<temp;i++)
					fibno[i]=fib(i);
				printf("No of values in the series \n");
				for(i=0;i<temp;i++)
					printf("%d\t",fibno[i]);
			}
		}
	}
}	
		
