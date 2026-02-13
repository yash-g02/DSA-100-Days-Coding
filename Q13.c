#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[100][100];
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Left ? Right
        for (i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Top ? Bottom
        for (i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            // Right ? Left
            for (i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            // Bottom ? Top
            for (i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}

