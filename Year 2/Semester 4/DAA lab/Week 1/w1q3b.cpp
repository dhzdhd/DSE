#include <iostream>
using namespace std;

void addEdge(int **graph, int v1, int v2)
{
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

void display(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "";
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    int n;
    cout << "Enter size";
    cin >> n;

    int **graph = new int *[n];

    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "1) Insert edge\n";
    cout << "2) Display\n";

    while (true)
    {
        cout << "Enter choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int v1, v2;
            cout << "Enter 2 vertices\n";
            cin >> v1;
            cin >> v2;

            addEdge(graph, v1, v2);
            break;
        }
        case 2:
        {
            display(graph, n);
            break;
        }
        default:
        {
            exit(0);
        }
        }
    }
}
