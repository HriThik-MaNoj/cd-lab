%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%token PLUS MINUS MULTIPLY DIVIDE
%token LPAREN RPAREN

%%
input:
    /* empty */
    | input line
    ;

line:
    '\n'
    | expr '\n'  { printf("Result: %d\n", $1); }
    ;

expr:
    expr PLUS term    { $$ = $1 + $3; }
    | expr MINUS term { $$ = $1 - $3; }
    | term
    ;

term:
    term MULTIPLY factor { $$ = $1 * $3; }
    | term DIVIDE factor { $$ = $1 / $3; }
    | factor
    ;

factor:
    NUMBER
    | LPAREN expr RPAREN { $$ = $2; }
    ;

%%

int main() {
    printf("Enter expressions to evaluate:\n");
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    return 1;
}

