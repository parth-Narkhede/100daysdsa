#include <stdio.h>
#include <string.h>
int main(){
char str[100];
int left, right, palindrome=1;

printf("Enter a string input: ");
scanf("%s", str);

left = 0;
right = strlen(str)-1;

while(left<right){
  if(str[left] != str[right]){
   palindrome = 0;
   break; 
 }
 left++;
 right--;
}
if(palindrome)
  printf("Given str is a  palindrome.");
else
  printf("Given str is not  a palindrome.");
printf("\n");
return 0;
}
