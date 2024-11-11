%{
#include "y.tab.h"  // Ensure this file is generated after yacc compilation
#include <stdio.h>
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[ \t]           { /* ignore whitespace */ }
\n              { return '\n'; }
.               { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

