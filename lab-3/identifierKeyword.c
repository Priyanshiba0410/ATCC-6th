#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("temp.txt", "r");
    if (!fp) {
        printf("Error: temp.txt not found\n");
        return 1;
    }

    char ch, buffer[50];
    int i;

    printf("\nLexical Analysis Output:\n\n");

    ch = fgetc(fp);

    while (ch != EOF) {

        
        if (isalpha(ch)) {
            i = 0;
            while (isalnum(ch)) {   
                buffer[i++] = ch;
                ch = fgetc(fp);
            }
            buffer[i] = '\0';
            printf("Identifier: %s\n", buffer);
            continue;
        }

        
        if (isdigit(ch)) {
            i = 0;
            while (isdigit(ch)) {  
                buffer[i++] = ch;
                ch = fgetc(fp);
            }
            buffer[i] = '\0';
            printf("Constant: %s\n", buffer);
            continue;
        }

        
        if (ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
            ch=='=' || ch=='<' || ch=='>' || ch=='%') {

            printf("Operator: %c\n", ch);
            ch = fgetc(fp);
            continue;
        }

    
        if (isspace(ch)) {
            while (isspace(ch)) {
                ch = fgetc(fp);   
            }
            continue;
        }

        
        printf("Special Character: %c\n", ch);
        ch = fgetc(fp);
    }

    fclose(fp);
    return 0;
}
