#include <stdio.h>

int fib(int n){
   if(n == 0)
     return 0;
   if(n == 1)
     return 1;

  return fib(n-1)+fib(n-2);
}

int main(){

int n;

printf("Enter a value for n: ");
scanf("%d", &n);

printf("The n-th number in fibonacci series is %d\n", fib(n));

return 0;
}
