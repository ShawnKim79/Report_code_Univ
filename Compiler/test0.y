%{
	#include <ctype.h>
	#include <stdio.h>
	#include <string.h> 
	#include <malloc.h>
	#define YYSTYPE char* 
	char*  stack[100];                 
	int size;
	int ssize;
	void push(char* );
	char* pop();
	int n;
	char* tempchar;
%}

%token NUMBER
%%

lines   : lines expr '\n'	
	{
		for(n=size ; n<ssize ; n++)
		{
			printf("%s",pop());
		}	
	}
         | lines '\n'
         |
         ;
expr   : term             {}
        | expr '+' term  {push("+");}
        | expr '-' term  {push("-");}
        ;

term   : factor           {}
        | term '*' factor  { push("*");}
        | term '/' factor  { push("/");}
        ;
factor : NUMBER     		{push($1);}
        | '(' expr ')'      {$$=$2}
        ;
 %%

#include "test.c"

void push(char* arg_string)
{         
	stack[ssize++] = arg_string;	         
}                               

char* pop()
{                     	   
	return stack[size++];
}

int main()
{             
	size =0;  
	ssize =0;
	yyparse();
	return 0;
}
                    
                 