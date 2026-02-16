#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int seen = 0;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                seen = 1;
                break;
            }
        }

        if (seen)
            continue;

        int count = 0;

        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d -> %d\n", arr[i], count);
    }

    return 0;
}
