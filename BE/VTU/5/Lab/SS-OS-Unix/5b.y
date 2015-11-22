%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token A B
%%
exp:A|B|A B
%%
main()
{
    printf("Enter a string\n");
    yyparse();
    printf("Valid expression\n");
}
yyerror()
{
    printf("Invalid Expression\n");
    exit(0);
}