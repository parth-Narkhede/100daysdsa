//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers.Shift existing elements to the right to make
//         space.

#include <stdio.h>

int main (){
  int i, C_index, size, element, one_index;
  
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size+1];

  printf("Enter the elements you want in the array: ");
  for(i=0; i<size; i++){
    scanf("%d", &arr[i]);
  }

  printf("Enter at which position you want to insert: ");
  scanf("%d", &one_index);

  printf("Enter the element you want to insert: "); 
  scanf("%d", &element);
 
  C_index = one_index-1;
 
  for(i=size; i>C_index; i--){
   arr[i] = arr[i-1];
  }
  arr[C_index] = element;
  size++;
     

  printf("The array after insertion is: ");
  for(i=0; i<size; i++){
     printf(" %d ", arr[i]);
  }
  printf("\n");
  return 0; 

}
