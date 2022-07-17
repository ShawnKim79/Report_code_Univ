%{
#include <ctype.h>
#include <stdio.h>
#define YYSTYPE double  /*double type for Yacc stack, yyval*/    
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc '<'
%right UMINUS

%%
lines    : lines expr '\n'    {printf("%g\n",$2);}
        | lines '\n'
        |    
       | error '\n'  { printf("reenter last line:");}
        ;
expr  : expr '+' expr     {$$ = $1 + $3; }
        | expr '-' expr     {$$ = $1 - $3; }
        | expr '*' expr     {$$ = $1 * $3; }
        | expr '/' expr     {$$ = $1 / $3; }
        | '(' expr  ')'      {$$ = $2 ; }
       | '-' expr  %prec UMINUS  {$$ = -$2;}  
        | NUMBER 
        ;
%%
#include "lex.c"

