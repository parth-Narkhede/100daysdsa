#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int size;
    printf("Enter number of nodes: ");
    scanf("%d", &size);

    if (size <= 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
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

    printf("Linked list elements are: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
