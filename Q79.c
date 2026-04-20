#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

AdjList graph[MAX];

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int dist) {
    int i;
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    i = heapSize;
    heapSize++;

    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[0];
    int i = 0;

    heapSize--;
    heap[0] = heap[heapSize];

    while (2 * i + 1 < heapSize) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

void addEdge(int u, int v, int w) {
    graph[u].edges[graph[u].size].node = v;
    graph[u].edges[graph[u].size].weight = w;
    graph[u].size++;

    graph[v].edges[graph[v].size].node = u;
    graph[v].edges[graph[v].size].weight = w;
    graph[v].size++;
}

void dijkstra(int n, int source) {
    int dist[MAX];
    int i;

    for (i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (heapSize > 0) {
        HeapNode current = pop();
        int u = current.node;

        for (i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].node;
            int w = graph[u].edges[i].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }

    for (i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    int i, u, v, w, source;

    scanf("%d %d", &n, &m);

    for (i = 0; i < MAX; i++)
        graph[i].size = 0;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
