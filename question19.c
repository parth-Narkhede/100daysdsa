#include <stdio.h>

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int x = arr[0], y = arr[1];
    int minSum = arr[0] + arr[1];
    if (minSum < 0) minSum = -minSum;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = arr[i] + arr[j];
            int absSum = sum;
            if (absSum < 0) absSum = -absSum;

            if (absSum < minSum) {
                minSum = absSum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("The two elements whose sum is closest to zero are: %d and %d\n", x, y);

    return 0;
}
