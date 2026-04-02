#include <stdio.h>

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n];

    int i, j;  // Declare loop variables here

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;
    printf("Enter edges (u v):\n");

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed graph
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
