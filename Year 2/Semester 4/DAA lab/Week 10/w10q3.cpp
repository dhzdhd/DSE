// Floyd's algorithm

#include <iostream>
using namespace std;

void floyd(int **graph, int n) {
    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                graph[i][j] = min(graph[i][j], (graph[i][k] + graph[k][j]));
            }
        }
    }
}

void display(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, e;

    cout << "Enter number of vertices and edges\n";
    cin >> n >> e;

    int **graph = new int *[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges & weight\n";
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a][b] = w;
    }

    floyd(graph, n);
    display(graph, n);

    return 0;
}
