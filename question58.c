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

int findIndex(int inorder[], int start, int end, int val){
    for(int i = start; i <= end; i++){
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex){

    if(start > end)
        return NULL;

    Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if(start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(Node* root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&preorder[i]);

    printf("Enter inorder traversal:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&inorder[i]);

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    printf("Postorder traversal:\n");
    postorder(root);

    return 0;
}
