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

int search(Node* root, int key){
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main(){

    int n, val, key;
    Node* root = NULL;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root = insert(root, val);
    }

    printf("Enter element to search: ");
    scanf("%d",&key);

    if(search(root, key))
        printf("Element found\n");
    else
        printf("Element not found\n");

    return 0;
}
