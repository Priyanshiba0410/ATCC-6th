%{
#include<stdio.h>
%}

%%
int|float|char|double|if|else|for|while   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                     { printf("Identifier: %s\n", yytext); }
[0-9]+                                    { printf("Number: %s\n", yytext); }
[+*/=<>-]                                 { printf("Operator: %s\n", yytext); }
[ \t\n]                                   { ; }
.                                         { printf("Special Symbol: %s\n", yytext); }
%%
int yywrap() {
    return 1;
}
