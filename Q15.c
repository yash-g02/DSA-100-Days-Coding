#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;
    int i, j;   // Declare loop variables here

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}

