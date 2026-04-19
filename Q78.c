#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];

int minKey(int key[], int visited[]) {
    int min = INT_MAX;
    int min_index = -1;
    int i;

    for (i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];
    int key[MAX];
    int i, count, u, v;
    int totalWeight = 0;

    for (i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;     // start from node 1
    parent[1] = -1;

    for (count = 1; count < n; count++) {
        u = minKey(key, visited);
        visited[u] = 1;

        for (v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (i = 2; i <= n; i++) {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main() {
    int i, u, v, w;

    scanf("%d %d", &n, &m);

    // Initialize graph
    for (i = 1; i <= n; i++) {
        int j;
        for (j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST());

    return 0;
}
