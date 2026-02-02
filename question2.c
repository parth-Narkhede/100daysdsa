#include <stdio.h>

int main(){
int i, size, C_index, one_index;

printf("Enter size of the array: ");
scanf("%d", &size);

int arr[size];

printf("Enter the elements you want in the array: ");
for(i=0; i<size; i++){
  scanf("%d", &arr[i]);
}

printf("Enter a  position to delete an element from the array: ");
scanf("%d", &one_index);

C_index = one_index-1;

for(i=C_index; i<size-1; i++){
arr[i]=arr[i+1];
}
size--;

printf("array after deletion: ");
for(i=0; i<size; i++){
printf(" %d ", arr[i]);
}
printf("\n");
return 0;
}

