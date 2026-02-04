#include <stdio.h>

int main(){
int i, left, right, size;

printf("Enter the size of the array: ");
scanf("%d", &size);

int arr[size];

printf("Enter the elements you want in the array: ");
for(i=0; i<size; i++){
  scanf("%d", &arr[i]);
}

left = 0;
right = size-1;

while(left < right){
int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

left++;
right--;
}

printf("The reversed array is: ");
for(i=0; i<size; i++){
   printf(" %d ", arr[i]);
}
printf("\n");
return 0;
}
