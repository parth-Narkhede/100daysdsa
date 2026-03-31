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

Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex){

    if(start > end)
        return NULL;

    Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if(start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

void preorder(Node* root){
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&inorder[i]);

    printf("Enter postorder traversal:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&postorder[i]);

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n-1, &postIndex);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}
