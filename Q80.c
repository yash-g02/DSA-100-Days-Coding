#include <stdio.h>

#define MAX 105
#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];
    int i, j, k;  // ? declare here (IMPORTANT)

    // Input
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
