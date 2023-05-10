// Kruskal's algorithm

#include <iostream>
using namespace std;

int n;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compareEdges(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    return edgeA[2] - edgeB[2];
}

void kruskalMST(int **graph) {
    int edges[1000][3];
    int numEdges = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[numEdges][0] = i;
                edges[numEdges][1] = j;
                edges[numEdges][2] = graph[i][j];
                numEdges++;
            }
        }
    }

    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    int parent[100];
    int rank[100];

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int e = 0;
    int i = 0;

    int result[100][2];
    while (e < n - 1 && i < numEdges) {
        int* nextEdge = edges[i++];

        int x = find(parent, nextEdge[0]);
        int y = find(parent, nextEdge[1]);

        if (x != y) {
            result[e][0] = nextEdge[0];
            result[e][1] = nextEdge[1];
            e++;
            unionSets(parent, rank, x, y);
        }
    }

    std::cout << "Edge \tWeight\n";
    for (int j = 0; j < e; j++) {
        std::cout << result[j][0] << " - " << result[j][1] << "\t" << graph[result[j][0]][result[j][1]] << "\n";
    }
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

    kruskalMST(graph);

    return 0;
}
