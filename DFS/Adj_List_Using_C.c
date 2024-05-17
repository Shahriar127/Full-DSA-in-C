#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int n; 

void DFS_list(int v) {
    struct Node* temp = adjList[v];

    printf("%d ", v);
    visited[v] = 1;

    while (temp) {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex]) {
            DFS_list(connectedVertex);
        }
        temp = temp->next;
    }
}

void addEdgeList(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

int main() {
    n = 5; 
    addEdgeList(0, 1);
    addEdgeList(0, 2);
    addEdgeList(1, 3);
    addEdgeList(1, 4);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS using adjacency list:\n");
    DFS_list(0); 

    return 0;
}
