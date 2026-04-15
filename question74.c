#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char **names = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(101);
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    qsort(names, n, sizeof(char *), cmp);

    char winner[101];
    int maxCount = 1, count = 1;
    strcpy(winner, names[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        strcpy(winner, names[n - 1]);
    }

    printf("Winner: %s %d\n", winner, maxCount);

    return 0;
}
