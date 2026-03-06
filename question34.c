#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* push(Node* top, int val){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = top;
    return newnode;
}

Node* pop(Node* top, int *val){
    if(top == NULL) return NULL;
    Node* temp = top;
    *val = temp->data;
    top = temp->next;
    free(temp);
    return top;
}

int main(){

    Node *top = NULL;
    char postfix[100];
    int a, b, result;
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    while(postfix[i] != '\0'){

        if(postfix[i] == ' '){
            i++;
            continue;
        }

        if(isdigit(postfix[i])){
            top = push(top, postfix[i] - '0');
        }

        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){

            top = pop(top, &b);
            top = pop(top, &a);

            if(postfix[i] == '+') result = a + b;
            else if(postfix[i] == '-') result = a - b;
            else if(postfix[i] == '*') result = a * b;
            else if(postfix[i] == '/') result = a / b;

            top = push(top, result);
        }

        i++;
    }

    if(top != NULL)
        printf("Result = %d\n", top->data);

    return 0;
}
