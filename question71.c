#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int is_occupied;
} HashEntry;

int main() {
    int m, n;
    
    printf("Enter table size (m): ");
    if (scanf("%d", &m) != 1) return 1;
    
    printf("Enter number of operations (n): ");
    if (scanf("%d", &n) != 1) return 1;

    HashEntry* hashTable = (HashEntry*)calloc(m, sizeof(HashEntry));
    if (hashTable == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    char op[10];
    int val;

    printf("\n--- Start entering operations ---\n");
    printf("Format: [INSERT/SEARCH] [Value]\n");

    for (int i = 0; i < n; i++) {
        printf("Operation %d: ", i + 1);
        scanf("%s %d", op, &val);

        int base_hash = ((val % m) + m) % m; 

        if (strcmp(op, "INSERT") == 0) {
            for (int j = 0; j < m; j++) {
                int idx = (base_hash + (long long)j * j) % m;
                
                if (!hashTable[idx].is_occupied) {
                    hashTable[idx].key = val;
                    hashTable[idx].is_occupied = 1;
                    break;
                }
                
                if (hashTable[idx].key == val) {
                    break;
                }
            }
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            
            for (int j = 0; j < m; j++) {
                int idx = (base_hash + (long long)j * j) % m;
                
                if (!hashTable[idx].is_occupied) {
                    break;
                }
                
                if (hashTable[idx].key == val) {
                    found = 1;
                    break;
                }
            }
            
            if (found) {
                printf("-> Result: FOUND\n");
            } else {
                printf("-> Result: NOT FOUND\n");
            }
        } else {
            printf("Invalid operation. Please use INSERT or SEARCH.\n");
            i--; // don't count this as a valid operation step
        }
    }

    free(hashTable);
    return 0;
}
