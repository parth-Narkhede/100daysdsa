#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;

    if (!head) {
        n->next = n;
        return n;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;

    return head;
}

void traverse(struct Node* head) {
    if (!head) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, x;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    printf("Circular Linked List elements: ");
    traverse(head);
      
    printf("\n");

    return 0;
}
