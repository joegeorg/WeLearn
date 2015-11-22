%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token LETTER DIGIT
%%
S:LETTER
 |S DIGIT 
 |S LETTER
%%
main()
{
    printf("Enter a variable: ");
    yyparse();
    printf("This is a valid variable\n");
}
yyerror()
{
    printf("Invalid variable\n");
    exit(0);
}

