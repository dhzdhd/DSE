// Prim's algorithm

#include <iostream>
#define MAX 999999

int n;

using namespace std;

int minKey(int key[], bool mstSet[])
{
    int min = MAX, min_index;
    for (int v = 0; v < n; ++v)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void display(int parent[], int **graph)
{
    std::cout << "Edge \tWeight\n";
    int countt = 0;
    for (int i = 1; i < n; ++i)
    {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        countt += graph[i][parent[i]];
    }
    cout << "Total: " << countt << endl;
}

void prim(int **graph)
{
    int parent[100];
    int key[100];
    bool mstSet[100];

    for (int i = 0; i < n; ++i)
    {
        key[i] = MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    display(parent, graph);
}

int main()
{
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

    prim(graph);

    return 0;
}
