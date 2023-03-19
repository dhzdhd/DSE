#include <iostream>
using namespace std;

int count = 0;

void dfs(int v, int n, int *visited, int **graph)
{
	count++;
	visited[v] = count;

	for (int i = 0; i < n; i++)
	{
		if (graph[v][i] == 1 && visited[i] == 0)
		{
			dfs(i, n, visited, graph);
		}
	}
}

int main()
{
	int n;

	cout << "Enter size of matrix\n";
	cin >> n;

	int **graph = new int *[n];
	int *visited = new int[n];

	cout << "Enter edges per indices, 1 for edge, 0 for no edge\n";
	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
		for (int j = 0; j <= i; j++)
		{
			cout << "i " << i << " | j " << j << "  ";
			cin >> graph[i][j];
			graph[j][i] = graph[i][j];
		}
		visited[i] = 0;
	}

	cout << "Graph is\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, n, visited, graph);
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << visited[i] - 1 << " ";
	}
	cout << endl;

	return 0;
}
