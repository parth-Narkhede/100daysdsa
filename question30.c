#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* head, int c, int e) {
    struct Node* n = malloc(sizeof(struct Node));
    n->coeff = c;
    n->exp = e;
    n->next = NULL;

    if (!head) return n;

    struct Node* t = head;
    while (t->next)
        t = t->next;
    t->next = n;

    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* t = head;

    while (t) {
        if (t->exp == 0)
            printf("%d", t->coeff);
        else if (t->exp == 1)
            printf("%dx", t->coeff);
        else
            printf("%dx^%d", t->coeff, t->exp);

        if (t->next)
            printf(" + ");

        t = t->next;
    }
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printf("Polynomial: ");
    printPolynomial(head);
     
    printf("\n");

    return 0;
}
