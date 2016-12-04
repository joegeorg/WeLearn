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
        printf("\nEnter the packet size[%d]:%d\n",i,psz[i]);
    printf("\nEnter the output rate/buffer\n:");
    scanf("%d %d",&ort,&bsz);
    for(i=0;i<5;i++)
    {
        if((psz[i]+prm)>bsz)
        {
            printf("Bucket size is not enough\n");
        }
        else
        {
            prm=prm+psz[i];
            printf("\nPsize %d\n",psz[i]);
            printf("Transmission %d\n",prm);
            while(1)
            {
                if(prm)
                {
                    if(prm<ort)
                    {
                        printf("\nTransmission done\n");
                        prm=0;
                        break;
                    }
                    else
                    {
                        printf("Size of packet %d transmitted\n",ort);
                        prm-=ort;
                        printf("Remaining size:%d",prm);
                    }
                }
                else
                {
                    printf("No packets remaining\n");
                    break;
                }
            }
        }
    }
    return 0;
}
