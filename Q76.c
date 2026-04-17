#include <stdio.h>

#define MAX 1000

int visited[MAX];
int adj[MAX][MAX];

void dfs(int node, int n) {
    int i;  // declare here
    visited[node] = 1;

    for (i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    int i, j;  // declare here

    scanf("%d %d", &n, &m);

    // initialize
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // input edges
    for (i = 0; i < m; i++) {
        int u, v;  // allowed here in C90 (inside block)
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
