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

Node* LCA(Node* root, int p, int q){
    if(root == NULL)
        return NULL;

    if(root->data == p || root->data == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if(left && right)
        return root;

    return left ? left : right;
}

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int p, q;
    printf("Enter two node values: ");
    scanf("%d %d",&p,&q);

    Node* root = buildTree(arr, n, 0);

    Node* ans = LCA(root, p, q);

    if(ans != NULL)
        printf("LCA: %d\n", ans->data);
    else
        printf("LCA not found\n");

    return 0;
}
