#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int size) {
    struct Node *head = NULL, *tail = NULL, *newNode;
    for (int i = 0; i < size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    printf("Enter size of first list: ");
    scanf("%d", &n);
    printf("Enter %d elements (sorted): ", n);
    struct Node* list1 = create(n);

    printf("\nEnter size of second list: ");
    scanf("%d", &m);
    printf("Enter %d elements (sorted): ", m);
    struct Node* list2 = create(m);

    struct Node* merged = merge(list1, list2);

    printf("\nMerged sorted list: ");
    print(merged);

    printf("\n");
    
    return 0;
}
