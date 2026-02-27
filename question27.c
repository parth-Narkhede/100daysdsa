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
    while (head) { c++; head = head->next; }
    return c;
}

int intersection(struct Node* a, struct Node* b) {
    int l1 = length(a), l2 = length(b);
    while (l1 > l2) { a = a->next; l1--; }
    while (l2 > l1) { b = b->next; l2--; }
    while (a && b) {
        if (a->data == b->data) return a->data;
        a = a->next;
        b = b->next;
    }
    return -1;
}

int main() {
    int n, m, x;
    struct Node *h1 = NULL, *h2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        h1 = insert(h1, x);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        h2 = insert(h2, x);
    }

    int ans = intersection(h1, h2);

    if (ans != -1)
        printf("Intersection point value: %d\n", ans);
    else
        printf("No Intersection\n");

    return 0;
}
