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

Node* buildTree(int arr[], int n, int i){
    if(i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i+1);
    root->right = buildTree(arr, n, 2*i+2);
    return root;
}

void rightView(Node* root){

    if(root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){

        int size = rear - front;

        for(int i = 0; i < size; i++){

            Node* temp = queue[front++];

            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left)
                queue[rear++] = temp->left;

            if(temp->right)
                queue[rear++] = temp->right;
        }
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

    Node* root = buildTree(arr, n, 0);

    printf("Right View:\n");
    rightView(root);

    return 0;
}
