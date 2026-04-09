#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0};
    int i, j;

    // Step 1: Calculate in-degree of each node
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Step 2: Enqueue nodes with in-degree 0
    for (i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce in-degree of adjacent nodes
        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle! No topological ordering possible.\n");
    }
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}
