%{
    #include<stdio.h>
    #include"y.tab.h"
%}
%%
a{10,} {return A;}
[b] {return B;}
. {return yytext[0];}
%%

