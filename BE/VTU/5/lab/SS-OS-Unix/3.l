%{
    #include<stdio.h>
    int count=0;
%}
%%
("int ")|("char")|("float")|("double") {
	int ch;
	ch=input();
	for(;;)
	{
		if(ch==',')
		{
		count++;
		}
		else if(ch==';' && count ==0)
		{
		break;
	 	}
		else if(ch== ';' )
		{ 
		count++;
		break;
		}
		ch=input();
	}
}
%%
main(int argc,char* argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("No of identifiers are %d\n\n ",count);
}
