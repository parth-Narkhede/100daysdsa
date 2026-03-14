#include <stdio.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];

int main(){

    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter queue elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&queue[i]);

    int top = -1;

    for(int i=0;i<n;i++)
        stack[++top] = queue[i];

    int front = 0;

    while(top != -1)
        queue[front++] = stack[top--];

    printf("Reversed queue:\n");

    for(int i=0;i<n;i++)
        printf("%d ",queue[i]);

    return 0;
}
