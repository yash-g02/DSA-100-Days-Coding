#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int source) {
    int visited[MAX];
    int i;  // declare here
    int node;

    // initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {  // no declaration here
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, source;
    int adj[MAX][MAX];
    int i, j;  // declare here

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    BFS(n, adj, source);

    return 0;
}
