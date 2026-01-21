%option noyywrap
%{
int v = 0, c = 0;
%}

%%
[aeiouAEIOU]    v++; 
[a-zA-Z]        c++; 
\n             {
                  printf("No of Vowels = %d\n", v);
                  printf("No of Consonants = %d\n", c);
                  v = c = 0;
               }
%%
void main() {
    yylex();
}
