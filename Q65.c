#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int V;

// DFS function
bool dfs(int node, int parent) {
    int i;
    visited[node] = true;

    for (i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

// Check cycle
bool hasCycle() {
    int i;

    for (i = 0; i < V; i++)
        visited[i] = false;

    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int E, i, j;

    scanf("%d %d", &V, &E);

    // initialize graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // input edges
    for (i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
