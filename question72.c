#include <stdio.h>

int main() {
    char s[100000]; 
    int seen[26] = {0}; 
    
    printf("Enter a string of lowercase letters: ");
    if (scanf("%99999s", s) != 1) {
        return 1;
    }
    
    char firstRepeated = '\0';
    
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        
        if (seen[index]) {
            firstRepeated = s[i];
            break; 
        }
        
        seen[index] = 1; 
    }
    
    printf("\n--- Result ---\n");
    if (firstRepeated != '\0') {
        printf("First repeated character: %c\n", firstRepeated);
    } else {
        printf("First repeated character: -1\n");
    }
    
    return 0;
}
