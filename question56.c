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
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

int isMirror(Node* a, Node* b){
    if(a == NULL && b == NULL)
        return 1;

    if(a == NULL || b == NULL)
        return 0;

    if(a->data != b->data)
        return 0;

    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int isSymmetric(Node* root){
    if(root == NULL)
        return 1;

    return isMirror(root->left, root->right);
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

    if(isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
