#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *queue = (int*)malloc(sizeof(int) * n);

    int front = 0;
    int rear = -1;

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        rear = (rear + 1) % n;
        queue[rear] = x;
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        front = (front + 1) % n;
    }

    printf("Queue elements from front to rear:\n");

    int count = 0;
    int i = front;

    while(count < n)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
        count++;
    }

    printf("\n");

    free(queue);
    return 0;
}
