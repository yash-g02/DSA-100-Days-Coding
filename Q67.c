#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    int visited[MAX];
};

int stack[MAX];
int top = -1;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    int i;  // declare here (C90 style)
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void push(int v) {
    stack[++top] = v;
}

void dfs(struct Graph* graph, int vertex) {
    struct Node* temp;

    graph->visited[vertex] = 1;
    temp = graph->adjLists[vertex];

    while (temp != NULL) {
        if (!graph->visited[temp->vertex]) {
            dfs(graph, temp->vertex);
        }
        temp = temp->next;
    }

    push(vertex);
}

void topologicalSort(struct Graph* graph) {
    int i;  // declare outside loop

    for (i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i);
        }
    }

    printf("Topological Ordering:\n");

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
