%{
    #include<stdio.h>
    int ch=0,w=0,sp=0,l=0;
%}
%%
[\n] {l++;}
[^ \t\n]+ {w++,ch+=yyleng;}
[ ] {sp++;}
%%
main(int argc,char *argv[])
{
        yyin=fopen(argv[1],"r");
        yylex();
        printf("no.of characters=%d\n",ch);
        printf("no.of words=%d\n",w);
        printf("no.of lines=%d\n",l);
        printf("no.of spaces=%d\n",sp);
}
