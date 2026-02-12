#include <stdio.h>

int main(){
 int i, j, m, n;
 
 printf("Enter rows and colum of a matrix respectively: ");
 scanf("%d %d", &m, &n);

if(m != n){
 printf("The matrix is not Symmetric");
 return 0;
} 

 int A[m][n], B[m][n];
 
 printf("Enter elments of the matrix:\n ");
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
    scanf("%d", &A[i][j]);
 }
}
int symmetric = 1;
for(i=0; i<m; i++){
 for(j=0; j<n; j++){
 if(A[i][j] != A[j][i]){
   symmetric = 0;
   break;
}
 }
if(symmetric == 0){
  break;
 }
}

if(symmetric == 0){
  printf("The matrix is not symmetric");
 }else{
   printf("Symmetric matrix");
  }

printf("\n");
return 0;
}
