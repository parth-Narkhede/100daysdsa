#include <stdio.h>

int main() {
    int size, k;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
 
    printf("Enter the elements you want in the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the position till you want to shift the elements to right: ");
    scanf("%d", &k);

    k = k % size;

    for (int i = 0; i < k; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
printf("\n");
    return 0;
}
