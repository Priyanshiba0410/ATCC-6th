#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;   

    printf("Enter a string of a's and b's: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];

        switch (state) {
            case 0: 
                if (ch == 'a')
                    state = 1;
                else if (ch == 'b')
                    state = 0;
                else {
                    printf("Invalid input\n");
                    return 0;
                }
                break;

            case 1: 
                if (ch == 'a')
                    state = 1;
                else if (ch == 'b')
                    state = 2;
                else {
                    printf("Invalid input\n");
                    return 0;
                }
                break;

            case 2: 
                if (ch == 'a')
                    state = 1;
                else if (ch == 'b')
                    state = 3;
                else {
                    printf("Invalid input\n");
                    return 0;
                }
                break;

            case 3: 
                if (ch == 'a')
                    state = 1;
                else if (ch == 'b')
                    state = 0;
                else {
                    printf("Invalid input\n");
                    return 0;
                }
                break;
        }
    }

    if (state == 3)
        printf("String ACCEPTED (ends with abb)\n");
    else
        printf("String REJECTED\n");

    return 0;
}
