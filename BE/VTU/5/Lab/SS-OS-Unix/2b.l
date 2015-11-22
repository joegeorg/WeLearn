%{
    int valid;
%}
%%
[a-zA-Z][ ](and|but|if|then|else|nevertheless)[ ][a-zA-Z] { valid=1; }
.|[\n] ;
%%
main()
{    
    printf("\nEnter the text: ");
    yylex();
    if(valid)
    {
        printf("\nStatement is compound!\n");
    }
    else
    {
        printf("\nStatement is simple!\n");
    }
}
