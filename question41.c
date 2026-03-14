#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL){
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

int dequeue(){
    if(front == NULL)
        return -1;

    Node *temp = front;
    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main(){

    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%s",op);

        if(strcmp(op,"enqueue")==0){
            scanf("%d",&x);
            enqueue(x);
        }

        else if(strcmp(op,"dequeue")==0){
            printf("%d\n",dequeue());
        }
    }

    return 0;
}
