%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S:E      {printf("%d",$$);}
E:E'+'E  {$$=$1+$3;}
 |E'-'E  {$$=$1-$3;}
 |E'*'E  {$$=$1*$3;}
 |E'/'E  {if($3==0)
{printf("Division by zero");
exit(0);
}
$$=$1/$3;
}
 |'('E')'  {$$=$2;}      
 | NUM; {$$=$1;}
%%
main()
{
    printf("Enter the expression\n");
    yyparse();
}
yyerror()
{
    printf("Error");
    exit(0);
}
