#include <stdio.h>
#include <string.h>

int main() {
    char str[20];

    printf("Enter input string: ");
    scanf("%s", str);

    if (
        strcmp(str, "da") == 0 ||
        strcmp(str, "bdc") == 0 ||
        strcmp(str, "dc") == 0 ||
        strcmp(str, "bda") == 0
       ) {
        printf("String is derived from the given grammar.\n");
    } else {
        printf("String is NOT derived from the given grammar.\n");
    }

    return 0;
}
