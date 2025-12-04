//append one file to another

#include<stdio.h>  

int main() {
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("file1.txt", "a");
    if (fp1 == NULL) {
        printf("Cannot open file1\n");
        return 1;
    }
    fp2 = fopen("test.txt", "r");
    if (fp2 == NULL) {
        printf("Cannot open file2\n");
        fclose(fp1);
        return 1;
    }

    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp1);
    }

    printf("File2 appended to File1 successfully!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}

