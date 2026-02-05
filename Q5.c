#include <stdio.h>

int main() {
    int p, q;
    int i, j;

    scanf("%d", &p);
    int a[p];
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}

