%{
#include<stdio.h>
int comment1=0,comment2=0;
%}
%%
"//".* {comment1++;}
"/*"([\n]|[^*/])*"*/" {comment2++;}
. fputs(yytext,yyout);
%%
main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("No of comment lines1(//)=%d\n",comment1);
printf("No of comment lines2(/*)=%d\n",comment2);
}

