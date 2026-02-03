#include <stdio.h>

int main() {
    int n, i, k;
    int comparisons = 0;

    printf("enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

