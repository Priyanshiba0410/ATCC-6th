//capitalize the first letter of every word in file

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp_in, *fp_out;
    char ch;
    int newWord = 1;   

    fp_in = fopen("file1.txt", "r");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fp_out = fopen("a.txt", "w");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        fclose(fp_in);
        return 1;
    }

    while ((ch = fgetc(fp_in)) != EOF) {
        if (newWord && isalpha(ch)) {
            ch = toupper(ch);
            newWord = 0;
        }

        fputc(ch, fp_out);

        if (ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch))
            newWord = 1;
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Capitalization complete! Check a.txt\n");

    return 0;
}
