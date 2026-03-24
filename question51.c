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

Node* insert(Node* root, int val){
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* LCA(Node* root, int p, int q){
    while(root != NULL){

        if(p < root->data && q < root->data)
            root = root->left;

        else if(p > root->data && q > root->data)
            root = root->right;

        else
            return root;
    }
    return NULL;
}

int main(){

    int n, val, p, q;
    Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root = insert(root, val);
    }

    printf("Enter two node values: ");
    scanf("%d %d",&p,&q);

    Node* ans = LCA(root, p, q);

    if(ans != NULL)
        printf("LCA: %d\n", ans->data);
    else
        printf("LCA not found\n");

    return 0;
}
