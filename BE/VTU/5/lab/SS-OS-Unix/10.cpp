#include<iostream>
using namespace std;
int n,sum,q;
struct time
{
  float at,bt,tot;
  int p;
}a[20];
void sjf()
{
     float ts=0,diff;
     int i,j=1,k =1;
     while(ts<sum)
     { 
       if(j<=n-1)
       {
          j++;
          diff=a[j].at-a[j-1].at;
          a[k].bt-=diff;
          ts+=diff;
          if(a[k].bt==0)
                a[k].tot=ts-a[k].at;
       }
       else
       {
          j=n;
          ts+=a[k].bt;
          a[k].bt=0;
          a[k].tot=ts-a[k].at;
       }
int small=999;

for(i=1;i<=j;i++)
 {
    if(a[i].bt<small&&a[i].bt!=0)
    {
        small=a[i].bt;
        k=i;
    }
 }
}}
void rr()
{
  float ts=0;
  int i;
  while(ts<sum)
  {
    for(i=1;i<=n;i++)
     {
       if(a[i].bt!=0)
        {
          if(a[i].bt<q)
            {
              ts+=a[i].bt;
              a[i].bt=0;
            }
            else
            {
               a[i].bt-=q;
               ts+=q;
            }
            if(a[i].bt==0)
                  a[i].tot=ts-a[i].at;

       }
    }
  }
}
int main()
{
  int i,j,ch;
  cout<<"\n enter the number of processes\n";
  cin>>n;
  sum=0;
  for(i=1;i<=n;i++)
  {
      cout<<"\n enter arrival time for processes"<<i<<":";
      cin>>a[i].at;
      cout<<"\n enter burst time for process"<<i<<":";
      cin>>a[i].bt;
      a[i].p= i;
      sum=sum+a[i].bt;
  }
 struct time temp;
 for(i=1;i<=n;i++)
   for(j=1;j<=n-i;j++)
   {
        if(a[j].at==a[j+1].at)
         {
           temp=a[j];
           a[j]=a[j+1];
           a[j-1]=temp;
         }
         cout<<"1.sjf 2.rr";
         cin>>ch;
         switch(ch)
         {
            case 1:sjf();
                   cout<<"\n\n shortest remaining job\n\n";
                   break;
            case 2:cout<<"enter q";
                   cin>>q;
                   rr(); 
                   cout<<"\n\n";
         }
         cout<<"\n\n\n\n"<<"p no"<<"\t"<<"tot"<<endl;
         for(i=1;i<=n;i++)
             cout<<a[i].p<<"\t"<<a[i].tot<<"\n";
         float avg=0;
         for(i=1;i<=n;i++)
         {
            avg+=a[i].tot;
         }
         cout<<"\n average tat is"<<avg/4<<endl;
         return(0);
       }
      }


         

