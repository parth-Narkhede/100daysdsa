#include <stdio.h>

int main() {
    int i, length;

    printf("Enter the length of the code: ");
    scanf("%d", &length);

    char str[length];

    printf("Enter the code: ");
    for(i = 0; i < length; i++) {
        scanf(" %c", &str[i]);
    }

    // reverse logic
    for(i = 0; i < length / 2; i++) {
        char temp = str[length - 1 - i];
        str[length - 1 - i] = str[i];
        str[i] = temp;
    }

    printf("The code in encrypted form: ");
    for(i = 0; i < length; i++) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}
