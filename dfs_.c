#include <stdio.h>
int main() {
    int n, graph[10][10], visited[10] = {0};
    int stack[10], top = -1;
    int start, i, first = 1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        scanf("%d", &graph[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &start);
    printf("DFS Path: ");
    stack[++top] = start;
    while (top != -1) {
        int node = stack[top--];
    if (visited[node] == 0) {
        if (!first) printf(" -> ");
        printf("%d", node);
        first = 0;
        visited[node] = 1;
    for (i = n - 1; i >= 0; i--) {
        if (graph[node][i] == 1 && visited[i] == 0) {
           stack[++top] = i;}
}
  } 
    }
    return 0;
}
