#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    Node *temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Queue elements from front to rear:\n");
    display();
    printf("\n");
    return 0;
}
