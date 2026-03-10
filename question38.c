#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1;
int rear = -1;

int empty(){
    return front == -1;
}

int size(){
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x){
    if(front == -1){
        front = rear = 0;
        dq[front] = x;
    }
    else if(front > 0){
        dq[--front] = x;
    }
    else{
        printf("Deque Overflow\n");
    }
}

void push_back(int x){
    if(front == -1){
        front = rear = 0;
        dq[rear] = x;
    }
    else if(rear < MAX-1){
        dq[++rear] = x;
    }
    else{
        printf("Deque Overflow\n");
    }
}

int pop_front(){
    if(empty()) return -1;
    int val = dq[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return val;
}

int pop_back(){
    if(empty()) return -1;
    int val = dq[rear];
    if(front == rear){
        front = rear = -1;
    }
    else{
        rear--;
    }
    return val;
}

int get_front(){
    if(empty()) return -1;
    return dq[front];
}

int get_back(){
    if(empty()) return -1;
    return dq[rear];
}

int main(){

    int n, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%s",op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(x);
        }

        else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(x);
        }

        else if(strcmp(op,"pop_front")==0){
            printf("%d\n",pop_front());
        }

        else if(strcmp(op,"pop_back")==0){
            printf("%d\n",pop_back());
        }

        else if(strcmp(op,"front")==0){
            printf("%d\n",get_front());
        }

        else if(strcmp(op,"back")==0){
            printf("%d\n",get_back());
        }

        else if(strcmp(op,"size")==0){
            printf("%d\n",size());
        }

        else if(strcmp(op,"empty")==0){
            printf("%d\n",empty());
        }
    }

    return 0;
}
