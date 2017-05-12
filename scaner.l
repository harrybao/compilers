digit [+-][0-9]+|[0-9]+|\.[0-9]+
id [A-Za-z][A-Za-z0-9]*
string \'[^\']+\'
notes \{[^\}]+\}
%%
[ |\t|\n]+
"var" {printf("21 -| %s\n",yytext);}
"if" {printf("22 -| %s\n",yytext);}
"then" {printf("23 -| %s\n",yytext);}
"else" {printf("24 -| %s\n",yytext);}
"while" {printf("25 -| %s\n",yytext);}
"for" {printf("26 -| %s\n",yytext);}
"begin" {printf("27 -| %s\n",yytext);}
"writeln" {printf("28 -| %s\n",yytext);}
"procedure" {printf("29 -| %s\n",yytext);}
"end" {printf("30 -| %s\n",yytext);}
"do" {printf("31 -| %s\n",yytext);}
"call" {printf("32 -| %s\n",yytext);}
"const" {printf("33 -| %s\n",yytext);}
{id} {printf("1  -| %s\n",yytext);}
{digit}+ {printf("2  -| %s\n",yytext);}
{string} {printf("50 -| %s\n",yytext);}
{notes} {printf("60 -| %s\n","Notes");}
"+" {printf("3  -| %s\n",yytext);}
"-" {printf("4  -| %s\n",yytext);}
"*" {printf("5  -| %s\n",yytext);}
"/" {printf("6  -| %s\n",yytext);}
"=" {printf("7  -| %s\n",yytext);}
">" {printf("8  -| %s\n",yytext);}
"<" {printf("9  -| %s\n",yytext);}
"<>" {printf("10 -| %s\n",yytext);}
"<=" {printf("11 -| %s\n",yytext);}
">=" {printf("12 -| %s\n",yytext);}
"(" {printf("13 -| %s\n",yytext);}
")" {printf("14 -| %s\n",yytext);}
"{" {printf("15 -| %s\n",yytext);}
"}" {printf("16 -| %s\n",yytext);}
";" {printf("17 -| %s\n",yytext);}
"," {printf("18 -| %s\n",yytext);}
"\"" {printf("19 -| %s\n",yytext);}
":=" {printf("20 -| %s\n",yytext);}
. {printf("100-| %s\n","error");}
%%
#include <ctype.h>
int main(int avgc,char *argv[]){
	freopen(argv[1],"r",stdin);
	yylex ( );
	return 0 ;
}
yywrap(){
	return 1;
}
