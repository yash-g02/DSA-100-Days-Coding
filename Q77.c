#include <stdio.h>

#define MAX 1000

int visited[MAX];
int adj[MAX][MAX];
int n, m;

void dfs(int node) {
    int i;
    visited[node] = 1;

    for (i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    scanf("%d %d", &n, &m);

    // Initialize
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // DFS from node 1
    dfs(1);

    // Check connectivity
    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}
