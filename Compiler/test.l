%{              
	#include <malloc.h>
	#include <string.h>
	
	extern char* yylval;
	int nsize;
%}
number [0-9]+\.?|[0-9]*\.[0-9]+ 

%%                            
[ ]	{/*skip*/}
{number}	{                   
		nsize =  strlen(yytext);
		yylval = malloc(nsize+1);
		memset(yylval,0,nsize+1);
		memcpy(yylval,yytext,nsize);
		return NUMBER;
		}

\n|.	{return yytext[0];}
%%

int yywrap(void) {return 1;}

