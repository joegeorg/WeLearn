%{
    #include<stdio.h>
    #include"y.tab.h"
    #include<math.h>
    extern int yylval;
%}
%%
[0-9]+  {   yylval=atoi(yytext);return NUM; }
[+]     {   return '+'; }
[-]     {   return '-'; }
[*]     {   return '*'; }
[/]     {   return '/'; }
.       {   return yytext[0];   }
%%
