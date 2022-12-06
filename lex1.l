%{
//#include "yaccExample.h"
#include "IOMngr.h"
#include "y.tab.h"

#define YY_INPUT(buf,result,max_size) \
	{ int c = getNextSourceChar(); \
          result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
        }

%}


letter [A-Za-z]
digit [0-9]
space [ ]
nl [\\\n]

%%
if					                {return IF;}
else                        {return ELSE;}
while                       {return WHILE;}
int					                {return Int;}
bool                        {return Bool;}
true                        {return BoolLit;}
false                       {return BoolLit;}
print					              {return Print;}
printlines                  {return Printlines;}
printspaces                 {return Printspaces;}
printString                 {return PrintString;}
read                        {return Read;}
{letter}({letter}|{digit})*	{return Ident;}
{digit}{digit}*		          {return IntLit;}
\"({letter}|{digit}|{space}|{nl})*\"     {return StringLit;}
\=\=					              {return EQ;}
\&\&                        {return AND;}
\|\|                        {return OR;}
\!\=                        {return NEQ;}
\<\=                        {return LTE;}
\<                          {return LT;}
\>\=                        {return GTE;}
\>                          {return GT;}
\!                          {return NOT;}
\=					                {return '=';}
\+					                {return '+';}
\-                          {return '-';}
\*					                {return '*';}
\/                          {return '/';}
\%                          {return '%';}
\^                          {return '^';}
\;					                {return ';';}
\{					                {return '{';}
\}					                {return '}';}
\(					                {return '(';}
\)					                {return ')';}
\,                          {return ',';}
\[                          {return '[';}
\]                          {return ']';}

[ ]				{}
\t				{}
\r				{}
\n				{}

.				{writeIndicator(getCurrentColumnNum());
				   writeMessage("Illegal Character in lex");}

%%

	
int yywrap () {
    return 1;
}
			
	
