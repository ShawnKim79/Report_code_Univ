#include <lex.h>

#define YYLEXFAST
#line 1 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.l"
              
	#include <malloc.h>
	#include <string.h>
	
	extern char* yylval;
	int nsize;

#line 13 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.c"
/* repeated because of possible precompiled header */
#include <lex.h>

#define YYLEXFAST
#include "test.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexaction(int action)
#else
int YYCDECL yylexaction(action)
int action;
#endif
{
	yyreturnflg = 1;
	switch (action) {
	case 1:
		{
#line 11 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.l"
/*skip*/
#line 117 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.c"
		}
		break;
	case 2:
		{
#line 12 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.l"
                   
		nsize =  strlen(yytext);
		yylval = malloc(nsize+1);
		memset(yylval,0,nsize+1);
		memcpy(yylval,yytext,nsize);
		return NUMBER;
		
#line 130 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.c"
		}
		break;
	case 3:
		{
#line 20 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.l"
return yytext[0];
#line 137 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = 0;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
#line 21 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.l"


int yywrap(void) {return 1;}


#line 159 "D:\\source_code\\Visual C++\\Report_code\\Compiler\\test.c"
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 81;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 3, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 5, 1 },
	{ 0, 0 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 7, 4 },
	{ 0, 0 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 4, 4 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 },
	{ 7, 5 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ -6, 1, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 1 },
	{ 0, 13, 2 },
	{ 0, 23, 3 },
	{ 0, 0, 3 },
	{ 5, 0, 2 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0
};

