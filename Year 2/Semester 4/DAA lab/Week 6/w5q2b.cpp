// Topological sort with source removal

#include <iostream>
using namespace std;

void topologicalSort(int **graph, int *indegree, int n)
{
	int output[100], m = 0;

	int k;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
		{
			output[m++] = i;
		}
	}
	for (int i = 0; i < m; i++)
	{
		k = output[i];
		cout << k << " ";
		for (int j = 0; j < n; j++)
		{
			if (graph[k][j] == 1)
			{
				indegree[j]--;
				if (indegree[j] == 0)
				{
					output[m++] = j;
				}
			}
		}
	}
}

int main()
{
	int n;

	cout << "Enter size of matrix\n";
	cin >> n;

	int **graph = new int *[n];
	int *indegree = new int[n];

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
	}

	cout << "Topological sort\n";
	topologicalSort(graph, indegree, n);

	cout << endl;
	return 0;
}
