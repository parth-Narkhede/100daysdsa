#include <stdio.h>

int main(){

int size1, size2;
int i=0, j=0, k=0;

printf("Enter the size of first log: ");
scanf("%d", &size1);

int log1[size1];

printf("Enter the arrival times of user in server1: ");
for(i=0; i<size1; i++){
 scanf("%d", &log1[i]);
}

printf("Enter the size of second log: ");
scanf("%d", &size2);

int log2[size2];

printf("Enter the arrival times of user in server2: ");
for(i=0; i<size2; i++){
 scanf("%d", &log2[i]);
}

int mergedlog[size1+size2];

i = 0;
j = 0;
k = 0;

while(i<size1 && j<size2){
  if(log1[i] < log2[j]){
    mergedlog[k] = log1[i];
    i++;
  }
  else{
    mergedlog[k] = log2[j];
    j++;
  }
  k++;
}

while(i<size1){
    mergedlog[k] = log1[i];
    i++;
    k++;
}

while(j<size2){
    mergedlog[k] = log2[j];
    j++;
    k++;
}

printf("array after merging: ");
for(int x=0; x<size1+size2; x++){
  printf(" %d ", mergedlog[x]);
}
printf("\n");
return 0;
}
