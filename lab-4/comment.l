%{
#include<stdio.h>
%}

%%
"//".*        { printf("Single line comment\n"); }
"/*"([^*]|[*][^/])*"*/" { printf("Multi-line comment\n"); }
.*            { printf("Not a comment\n"); }
%%
int yywrap() {
    return 1;
}
