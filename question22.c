#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Total nodes: 0");
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total nodes in linked list: %d", count);
    printf("\n");
    return 0;
}
