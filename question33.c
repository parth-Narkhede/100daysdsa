#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

int main(){

    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0'){

        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }

        else if(infix[i] == '('){
            push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(top != -1 && peek() != '('){
                postfix[j++] = pop();
            }
            pop();
        }

        else{
            while(top != -1 && precedence(peek()) >= precedence(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
