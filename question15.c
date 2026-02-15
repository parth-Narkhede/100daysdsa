#include <stdio.h>
int main(){
int i, j, m, n;

printf("Enter the number of rows and column: ");
scanf("%d %d", &m, &n);

int matrix[m][n];

printf("Enter the Elements you want in the matrix: \n");
for(i=0; i<m; i++){
 for(j=0; j<n; j++){
 scanf("%d", &matrix[i][j]);
 }
}
int sum = 0;
for(i=0; i<m; i++){
 for(j=0; j<n; j++){
  if(i == j){
   sum += matrix[i][j];
  } 
 }
}

printf("The sum of diagonal elements is: %d", sum);

printf("\n");
return 0;
}
 
