#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct QNode{
    Node* node;
    int hd;
}QNode;

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

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr, n, 0);

    QNode queue[1000];
    int front = 0, rear = 0;

    int minHD = 0, maxHD = 0;

    int columns[2000][100];
    int size[2000] = {0};

    queue[rear++] = (QNode){root, 0};

    while(front < rear){

        QNode curr = queue[front++];
        Node* node = curr.node;
        int hd = curr.hd;

        int index = hd + 1000;

        columns[index][size[index]++] = node->data;

        if(hd < minHD) minHD = hd;
        if(hd > maxHD) maxHD = hd;

        if(node->left)
            queue[rear++] = (QNode){node->left, hd-1};

        if(node->right)
            queue[rear++] = (QNode){node->right, hd+1};
    }

    printf("Vertical Order Traversal:\n");

    for(int i=minHD;i<=maxHD;i++){
        int idx = i + 1000;
        for(int j=0;j<size[idx];j++)
            printf("%d ", columns[idx][j]);
        printf("\n");
    }

    return 0;
}
