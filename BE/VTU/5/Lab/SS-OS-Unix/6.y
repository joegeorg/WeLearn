%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token A B
%%
exp:A B;
%%
main()
{
    printf("Enter a string\n");
    yyparse();
    printf("Valid string\n");
}
yyerror()
{
    printf("Invalid\n");
    exit(0);
}