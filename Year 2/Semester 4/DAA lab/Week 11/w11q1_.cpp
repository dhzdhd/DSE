// Prim's algorithm

#include <iostream>
using namespace std;

bool in(int vertex, int *vertices, int n) {
    for (int i = 0; i < n; i++) {
        if (vertex == vertices[i]) {
            return true;
        }
    }
    return false;
}

void prim(int **graph, int n, int e, int *vertices, int **edges) {
    int cv = 0;
    vertices[cv++] = 0;

    for (int i = 0; i < cv; i++) {
        int start = vertices[i];

        int min = 100000;
        int j;

        for (j = 0; j < n && !in(j, vertices, cv); j++) {
            int edgeVal = graph[start][j];

            if (edgeVal != 0 && edgeVal < min) {
                cout << start << " " << j << " ";
                min = edgeVal;
            }
        }
        if (cv < n) {
            vertices[cv++] = j;
            edges[start][j] = min;
        }
    }
}

int main() {
    int n, e;

    cout << "Enter number of vertices and edges\n";
    cin >> n >> e;

    int **graph = new int *[n];
    int **edges = new int *[n];
    int *vertices = new int[n];

    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
            edges[i][j] = 0;
        }
    }

    cout << "Enter edges & value\n";
    for (int i = 0; i < e; i++) {
        int a, b, val;
        cin >> a >> b >> val;
        graph[a][b] = val;
        graph[b][a] = val;
    }

    prim(graph, n, e, vertices, edges);

    cout << "MST is\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
