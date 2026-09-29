#include <stdio.h>

#define MAX 100
#define INF 99999

int main() {
    int n;
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX] = {0};
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no direct edge)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &source);

    source--;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        if (i == source)
            distance[i] = 0;
        else if (graph[source][i] != 0)
            distance[i] = graph[source][i];
        else
            distance[i] = INF;
    }

    // Dijkstra's algorithm
    for (int count = 0; count < n - 1; count++) {

        int min = INF;
        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source + 1);

    for (int i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d : Not reachable\n", i + 1);
        else
            printf("Vertex %d : %d\n", i + 1, distance[i]);
    }

    return 0;
}
