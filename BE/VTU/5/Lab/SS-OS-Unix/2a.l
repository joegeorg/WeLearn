%{
    #include<stdio.h>
    int flag=0,i=0,j=0,temp;
    char *a1[10],*a2[20];
%}
opr [ ]*[\+\-\*\/][ ]*
opnd [a-zA-Z][a-zA-Z0-9]*
%x P Q R
%%
^{opr}   {BEGIN R;}
<R>.*\n  {flag=1;}
{opnd}  {a1[i++]=(char*)strdup(yytext);BEGIN P;}
<P>{opr}  {a2[j++]=(char*)strdup(yytext);BEGIN Q;}
<P>{opr}+ {BEGIN R;}
<P>{opr}+$ {BEGIN R;}
<Q>{opnd} {a1[i++]=(char*)strdup(yytext);BEGIN P;}
%%
main()
{
    printf("Enter an expression:\n");
    yylex();
    if(flag==1)
    {
        printf("Invalid expression\n");
        exit(0);
    }
    printf("\nValid expression:");
    printf("\nOperators are\n");
    for(temp=0;temp<i;temp++)
        printf("%s\t",a1[temp]);
    printf("\nOperands are\n");
    for(temp=0;temp<j;temp++)
        printf("%s   ",a2[temp]);
    printf("\n");
}

