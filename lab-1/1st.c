//1. create , open file and count chars , spaces , tabs, and new lines 

#include <stdio.h>

int main(){
    FILE *fp;
    char filename[50];
    char ch;
    int chars=0, spaces=0, tabs=0, newlines=0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("file not found , creating new file...\n");
        fp = fopen(filename, "w");
        fprintf(fp, "hello world\nThis is a test file.\tEnjoy coding");
        fclose(fp);

        fp = fopen(filename, "r");
    }

    while ((ch = fgetc(fp)) != EOF){
        chars++;
        if (ch == ' ')
            spaces++;
        else if (ch == '\t')
            tabs++;
        else if (ch == '\n')
            newlines++;
    }

    fclose(fp);

   
    printf("Total Characters : %d\n", chars);
    printf("Spaces           : %d\n", spaces);
    printf("Tabs             : %d\n", tabs);
    printf("New Lines        : %d\n", newlines);

    return 0;
}