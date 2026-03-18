#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void levelOrder(Node* root){

    if(root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){

        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if(curr->left)
            queue[rear++] = curr->left;

        if(curr->right)
            queue[rear++] = curr->right;
    }
}

int main(){

    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    Node* root = nodes[0];

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
