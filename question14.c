#include <stdio.h>
int main(){
 int i, j, m, n;
 printf("Enter rows and columns of a matrix: "); 
 scanf("%d %d", &m, &n);
 if(m!=n) 
  printf("The Matrix is not a square matrix");
 
 int matrix[m][n];
 
 printf("Enter the element of the matrix:\n");
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   scanf("%d", &matrix[i][j]);
   }
}
int rowcount = 1;
int columncount = 1;

for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
        if(i == j){
            if(matrix[i][j] != 1){
                rowcount = 0;
                break;
            }
        }
        else{
            if(matrix[i][j] != 0){
                columncount = 0;
                break;
            }
        }
    }

    if(rowcount == 0 || columncount == 0){
        break;
    }
}

if(columncount == 0 || rowcount == 0){
    printf("The matrix entered by the user is not an identity matrix");
  }
else
  printf("The matrix is an identity matrix");

printf("\n");
return 0;
}

  
  
