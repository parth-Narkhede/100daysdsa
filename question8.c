#include <stdio.h>

int power(int a, int b){
  if(b == 0)
    return 1;
  if(b == 1)
    return a;

  return a * power(a, b-1);
}

int main(){

 int a, b;

 printf("Enter the number and the power of the number you want: ");
 scanf("%d %d", &a, &b);

  printf("The result is: %d\n", power(a,b));

return 0;
}
