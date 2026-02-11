#include <stdio.h>

int main(){
int m, n, i, j;

printf("Enter the number of rows and column: ");
scanf("%d %d", &m, &n);

int a[m][n], b[m][n], sum[m][n];
printf("Enter the elements of first matrix:\n ");
for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   scanf("%d", &a[i][j]);
  }
}
printf("Enter the elements of second matrix:\n ");
for(i=0; i<m; i++){
  for(j=0; j<n; j++){
  scanf("%d", &b[i][j]);
  }
}
for(i=0; i<m; i++){
 for(j=0; j<n; j++){
  sum[i][j] = a[i][j]+b[i][j];
  }
}
printf("Resultant matrix: \n");
for(i=0; i<m; i++){
 for(j=0; j<n; j++){
 printf(" %d ", sum[i][j]);
 }
printf("\n");
}
printf("\n");
return 0;
}
