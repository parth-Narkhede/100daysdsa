#include <stdio.h>
int main(){
int i, size, max, min;

printf("Enter the size of the array: ");
scanf("%d", &size);

int arr[size];

printf("Enter the elemnts you want in the array: ");
for(i=0; i<size; i++){
 scanf("%d", &arr[i]);
}

max = arr[0];
min = arr[0];

for(i=0; i<size-1; i++){
 if(max < arr[i+1])
    max = arr[i+1];

 if(min > arr[i+1])
   min = arr[i+1];
}

printf("The maximum value in the array is %d\n", max);
printf("The minimum value in the array is %d", min);
printf("\n"); 
return 0;
}

