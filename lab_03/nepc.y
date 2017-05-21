%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c" 

YYSTYPE reg[26]={0};
BIGINT ival;

enum Display{DEC_ON, HEX_ON, OCT_ON};
enum Display dflag=DEC_ON;
int i;

%}

%token		CLEAR EXIT LIST ERASE DEC HEX OCT HELP
%token		NUM	REG
%token		ADD SUB MUL DIV MOD LSHIFT RSHIFT
%token		AND OR  NOT LESS MORE
%token		BITAND BITOR BITXOR BITREV

%left		OR
%left		AND
%left		BITOR
%left		BITXOR
%left		BITAND
%left		LESS MORE
%left		LSHIFT RSHIFT
%left		ADD	SUB
%left		MUL	DIV MOD
%right		RMINUS BITREV NOT

%%
	
lines		: lines statement '\n'		
		| lines '\n'				{printf("--> ");}
		| lines error '\n'			{yyerrok;printf("\n--> ");}
		| lines cmdline	'\n'		
		|
		;
		
statement	: expr				{
								if(dflag==DEC_ON)printf( "\t=%g\n--> " , $1 );
								else if(dflag==HEX_ON)printf( "\t=0x%08X\n--> " , (BIGINT)$1 );
								else printf( "\t=0%o\n--> " , (BIGINT)$1 );
							}
		| REG '=' expr			{
								i=(int)$1; reg[i] = $3 ; 
								if(dflag==DEC_ON) printf( "\t%c=%g\n--> " , 'a'+i,reg[i] );
								else if(dflag==HEX_ON) printf( "\t%c=0x%08X\n--> " , 'a'+i,(BIGINT)reg[i] );
								else  printf( "\t%c=0%o\n--> " , 'a'+i,(BIGINT)reg[i] );
							}
		;
		
expr		: expr ADD expr			{ $$ = $1 + $3 ; }
		| expr SUB expr			{ $$ = $1 - $3 ; }
		| expr MUL expr			{ $$ = $1 * $3 ; }
		| expr DIV expr			{ $$ = $1 / $3 ; }
		| expr MOD expr			{ $$ = (BIGINT)$1 % (BIGINT)$3 ; }
		| expr BITAND expr		{ $$ = (BIGINT)$1 & (BIGINT)$3 ; }
		| expr BITOR expr		{ $$ = (BIGINT)$1 | (BIGINT)$3 ; }
		| expr BITXOR expr		{ $$ = (BIGINT)$1 ^ (BIGINT)$3 ; }
		| expr LSHIFT expr		{ $$ = (BIGINT)$1 << (BIGINT)$3 ; }
		| expr RSHIFT expr		{ $$ = (BIGINT)$1 >> (BIGINT)$3 ; }
		| expr AND expr			{ $$ = (BIGINT)$1 && (BIGINT)$3 ; }
		| expr OR expr			{ $$ = (BIGINT)$1 || (BIGINT)$3 ; }
		| expr LESS expr		{ $$ = $1<$3?1:0; }
		| expr MORE expr		{ $$ = $1>$3?1:0; }
		| '(' expr ')'			{ $$ = $2 ; }
		| SUB expr %prec RMINUS	{ $$ = -$2 ; }
		| BITREV expr			{ $$ = ~((BIGINT)$2); }
		| NOT expr 			{ $$ = !( (BIGINT)$2 ) ; }
		| NUM				{ $$ = $1 ; }
		| REG				{ ival=(int)$1;$$ = reg[ival] ; }
		;

cmdline	: EXIT 				{ exit(0); }
		| CLEAR				{ printf("\033[2J\033[1;1H\n--> "); }
		| HEX				{ dflag=HEX_ON; printf(">> Hex display mod on!\n--> "); }
		| DEC				{ dflag=DEC_ON; printf(">> Dec display mod on!\n--> "); }
		| OCT 				{ dflag=OCT_ON; printf(">> Oct display mod on!\n--> "); }
		| LIST 				{ 
								for(i=0;i<26;i++)
								{
									if(dflag==DEC_ON)printf("\t%c=%g\n",'a'+i,reg[i]); 
									else if(dflag==HEX_ON)printf("\t%c=0x%08X\n",'a'+i,(BIGINT)reg[i]);
									else printf("\t%c=0%o\n",'a'+i,(BIGINT)reg[i]);
								}
								printf("--> ");
							}
		| ERASE 				{ for(i=0;i<26;i++)reg[i]=0; printf(">>All registers erased!\n--> ");}
		| HELP				{
								printf(">> COMMANDS:\n");
								printf("> help: Display this help section.\n");
								printf("> clear: Clear the screen.\n");
								printf("> dec: Decimal mode to display  numbers or registers.\n");
								printf("> hex: Hexadecimal mode to display numbers or registers.\n");
								printf("> oct: Octal mode to display numbers or registers.\n");
								printf("> list: List the values in the 26 registers which are ranged from 'a'/'A' to 'z'/'Z'.\n");
								printf("> erase: Reset all registers to 0.\n");
								printf("> exit: Quit this program.\n");
								printf("--> ");
							}
		;		

%%

int yyerror(char *str)
{
 	fprintf(stderr,"Error: %s\n",str);
	return 1;      
 }

int yywrap()
{
         
      return 1;
}
int main()
{
	printf("--------------------------------------------------------------\n");
	printf(">> nepc - A mini limited precision caculator.\n");
	printf(">> Copyright (C) 2005 neplusultra@linuxsir.org\n");
	printf(">> nepc is open software; you can redistribute it and/or modify\n\
   it under the terms of the version 2.1 of the GNU Lesser \n\
   General Public License as published by the Free Software\n\
   Foundation.\n");
	printf("--------------------------------------------------------------\n");
	printf("--> ");

	yyparse();
}
