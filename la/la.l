%{
#include <stdio.h>
%}

digit   [0-9]
letter  [a-zA-Z]

keyword "unknown"|"int"|"float"|"char"|"return"

%% 
{digit}+                       { printf("Integer: %s\n", yytext); }
{digit}+"."{digit}+            { printf("Float: %s\n", yytext); }
{keyword}                      { printf("Keyword: %s\n", yytext); }
{letter}({letter}|{digit})*    { printf("Identifier: %s\n", yytext); }
[\t\n]+                        { /* Ignore whitespace */ }
.                              { printf("Unknown character: %s\n", yytext); }

%% 
int main() {
    yylex();  
    return 0;
}
int yywrap() {
    return 1;
}

