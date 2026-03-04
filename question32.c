#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top >= 0)
        top--;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main() {
    int n, m, x;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack elements from top to bottom: ");
    display();
    
    printf("\n");
  
    return 0;
}
