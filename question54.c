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

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr, n, 0);

    if(root == NULL)
        return 0;

    Node* s1[1000];
    Node* s2[1000];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    printf("Zigzag Traversal:\n");

    while(top1 != -1 || top2 != -1){

        while(top1 != -1){
            Node* temp = s1[top1--];
            printf("%d ", temp->data);

            if(temp->left)
                s2[++top2] = temp->left;

            if(temp->right)
                s2[++top2] = temp->right;
        }

        while(top2 != -1){
            Node* temp = s2[top2--];
            printf("%d ", temp->data);

            if(temp->right)
                s1[++top1] = temp->right;

            if(temp->left)
                s1[++top1] = temp->left;
        }
    }

    return 0;
}
