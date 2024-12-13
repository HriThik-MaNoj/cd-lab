%{
#include "y.tab.h"   // Include the header file generated by YACC
%}

%%

[a-zA-Z_][a-zA-Z_0-9]*   return id;     // Match identifiers
[0-9]+(\.[0-9]*)?         return num;    // Match numbers (integer/decimal)
[+\-/*]                   return op;     // Match operators (+, -, *, /)
.                         return yytext[0];  // Return any other character
\n                        return 0;       // End of line

%%

int yywrap() {
    return 1;  // End of input
}
