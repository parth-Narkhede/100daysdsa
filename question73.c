#include <stdio.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    printf("Enter a string: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", s[i]);
            return 0;
        }
    }

    printf("First non-repeating character: $\n");

    return 0;
}
