#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    if (!head) return n;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

int length(struct Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int n = length(head);
    k = k % n;
    if (k == 0) return head;

    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("List after rotation: ");
    printList(head);
     
    printf("\n"); 
   
    return 0;
}
