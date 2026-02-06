#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements you want in the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // If array has 0 or 1 element
    if (size <= 1) {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        return 0;
    }

    int i = 0;  

    for (int j = 1; j < size; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    
   for (int k = 0; k <= i; k++) {
        printf("%d ", arr[k]);
    }
printf("\n");
    return 0;
}
