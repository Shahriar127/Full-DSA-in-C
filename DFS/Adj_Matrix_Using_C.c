#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int n; 

void DFS_matrix(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFS_matrix(i);
        }
    }
}

void addEdgeMatrix(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; 
}

int main() {
    n = 5; 
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(1, 4);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS using adjacency matrix:\n");
    DFS_matrix(0); 

    return 0;
}
