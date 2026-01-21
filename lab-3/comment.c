#include <stdio.h>

int main() {
    FILE *f1, *f2;
    char ch, next;

    f1 = fopen("input.txt", "r");
    f2 = fopen("temp.txt", "w");

    if (!f1 || !f2) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(f1)) != EOF) {

        
        if (ch == '/') {
            next = fgetc(f1);
            if (next == '/') {
                while ((ch = fgetc(f1)) != EOF && ch != '\n');
                fputc('\n', f2);
                continue;
            }
            else if (next == '*') {
                
                while ((ch = fgetc(f1)) != EOF) {
                    if (ch == '*' && (next = fgetc(f1)) == '/') {
                        break;
                    }
                }
                continue;
            }
            else {
                
                fputc(ch, f2);
                fputc(next, f2);
                continue;
            }
        }

        
        fputc(ch, f2);
    }

    fclose(f1);
    fclose(f2);

    printf("Comments removed successfully.\n");
    return 0;
}
