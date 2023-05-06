// Topological sort with DFS

#include <iostream>
using namespace std;

void dfs(int u, int *visited, int n, int *stack, int &m, int **graph)
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (graph[u][v] == 1 && !visited[v])
        {
            dfs(v, visited, n, stack, m, graph);
        }
    }
    stack[m++] = u;
}

void topologicalSort(int **graph, int *indegree, int *visited, int n)
{
    int stack[100];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, n, stack, m, graph);
        }
    }
    cout << "Topological sort order\n";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter size of matrix\n";
    cin >> n;

    int **graph = new int *[n];
    int *indegree = new int[n];
    int *visited = new int[n];

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    cout << "Enter edges per indices, 1 for edge, 0 for no edge\n";
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cout << "i " << i << " | j " << j << "  ";
            cin >> graph[i][j];

            if (graph[i][j] == 1)
                indegree[j]++;
        }
        visited[i] = 0;
    }

    topologicalSort(graph, indegree, visited, n);

    cout << endl;
    return 0;
}
