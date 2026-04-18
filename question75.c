#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003

typedef struct HashNode {
    int prefix_sum;
    int index;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

int hashFunction(int key) {
    int hash = key % HASH_SIZE;
    if (hash < 0) {
        hash += HASH_SIZE;
    }
    return hash;
}

int search(int prefix_sum) {
    int hashIndex = hashFunction(prefix_sum);
    HashNode* current = hashTable[hashIndex];
    
    while (current != NULL) {
        if (current->prefix_sum == prefix_sum) {
            return current->index;
        }
        current = current->next;
    }
    return -1;
}

void insert(int prefix_sum, int index) {
    int hashIndex = hashFunction(prefix_sum);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->prefix_sum = prefix_sum;
    newNode->index = index;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int maxLenSubarraySumZero(int arr[], int n) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int max_len = 0;
    int current_prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        current_prefix_sum += arr[i];

        if (current_prefix_sum == 0) {
            max_len = i + 1;
        } else {
            int prev_index = search(current_prefix_sum);

            if (prev_index != -1) {
                int current_len = i - prev_index;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            } else {
                insert(current_prefix_sum, i);
            }
        }
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenSubarraySumZero(arr, n));

    return 0;
}
