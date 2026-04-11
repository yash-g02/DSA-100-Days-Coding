#include <stdio.h>
#include <limits.h>

#define MAX 1000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    int i, j;  // declare loop variables here

    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];

    // Initialize distances
    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax edges n-1 times
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE in C\n");
            return 0;
        }
    }

    // Print shortest distances
    printf("Shortest distances from source %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
