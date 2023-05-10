// Djikstra's algorithm

#include <iostream>
#define MAX 999999
using namespace std;

int n;

int minDistance(int dist[], bool visited[]) {
    int minDist = MAX;
    int minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printPath(int parent[], int target) {
    if (parent[target] == -1)
        return;

    printPath(parent, parent[target]);
    std::cout << " -> " << target;
}

void printDistances(int dist[], int parent[], int src) {
    std::cout << "Vertex\tDistance\tPath\n";

    for (int i = 0; i < n; i++) {
        std::cout << i << "\t" << dist[i] << "\t\t" << src;
        printPath(parent, i);
        std::cout << "\n";
    }
}

void dijkstra(int **graph, int src) {
    int dist[100];
    bool visited[100];
    int parent[100];

    for (int i = 0; i < n; i++) {
        dist[i] = MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printDistances(dist, parent, src);
}

int main() {
    int e;

    cout << "Enter number of vertices and edges\n";
    cin >> n >> e;

    int **graph = new int *[n];

    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges & value\n";
    for (int i = 0; i < e; i++) {
        int a, b, val;
        cin >> a >> b >> val;
        graph[a][b] = val;
        graph[b][a] = val;
    }

    dijkstra(graph, 0);

    return 0;
}
