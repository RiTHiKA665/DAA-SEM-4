#include <stdio.h>

int main() {
    int n, graph[10][10], visited[10] = {0};
    int queue[10], front = 0, rear = 0;
    int start, i;

    printf("Enter number of nodes: ");
     scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);
    printf("Enter starting node: ");
     scanf("%d", &start);
    printf("BFS Path: ");
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
        }
     }
 }
    return 0;
}
