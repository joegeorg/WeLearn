#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
int  parsecondition(char[],int ,char *,int);  
void gen(char[],char[],char[],int);  

int main()  
{  
  int counter=0,stlen=0,elseflag=0;  
  char stmt[60];  
  char strB[54];  
  char strS1[50];  
  char strS2[45];  
  
  printf("format of if statement\n example............\n");  
  printf("if(a<b)then(s,a);\n");  
  printf("if(a<b)then(s,a) else (s,b);\n\n");  
  printf("enter the statement\n");  
  scanf("%s",&stmt);  
  
  stlen=strlen(stmt);  
  counter=counter+2;  
  counter=parsecondition(stmt,counter,strB,stlen);  
  if(stmt[counter]==')')  
    counter++;  
  counter=counter+3;  
  counter=parsecondition(stmt,counter,strS1,stlen);  
  if(stmt[counter+1]==';')  
  {  
    printf("\n parsing the input statement...\n");  
    gen(strB,strS1,strS2,elseflag);  
    return 0;  
  }  
  if(stmt[counter]==')')  
   counter++;  
 counter=counter+3;  
 counter=parsecondition(stmt,counter,strS2,stlen);  
 counter=counter+2;  
 if(counter==stlen)  
 {  
  elseflag=1;  
  printf("\n parsing the input statement");  
  gen(strB,strS1,strS2,elseflag);  
  return 0;  
}  
return 0;  
}


int parsecondition(char input[],int cntr , char *dest, int totallen)  
{  
  int index=0,pos=0;  
  while(input[cntr]!='(' && cntr<=totallen)  
    cntr++;  
  if(cntr>=totallen)  
    return 0;  
  index=cntr;  
  while(input[cntr]!=')')  
    cntr++;  
  if(cntr>=totallen)  
    return 0;  
  while(index<=cntr)  
    dest[pos++]=input[index++];  
  dest[pos]='\0';  
  return cntr;  
}  
void gen(char B[],char S1[],char S2[],int elsepart)  
{  
  int Bt=101,Bf=102,Sn=103;  
  printf("\n\t if %s goto %d",B,Bt);  
  printf("\n\t goto %d",Bf);  
  printf("\n %d:",Bt);  
  printf("%s",S1);  
  if(!elsepart)  
    printf("\n %d:",Bf);  
  else  
  {  
   printf("\n\t goto %d",Sn);  
   printf("\n %d : %s",Bf,S2);  
   printf("\n %d:",Sn);  
 }  
}  

