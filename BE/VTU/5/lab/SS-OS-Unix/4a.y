%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token 	ID
%left 	'+' '-' '*' '/'
%%
E:E'+'E
 |E'-'E
 |E'*'E
 |E'/'E
 |ID;
%%
main()
{   
    printf("Enter the expression\n ");
    yyparse();
    printf("It is A Valid expression\n\n ");
}

yyerror(){
    printf("Invalid expression\n");
    exit(0);
}
