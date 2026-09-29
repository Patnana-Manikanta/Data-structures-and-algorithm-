#include <stdio.h>

#define MAX 100

int main() {
    int n, graph[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &start);

    start--;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current + 1);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}
