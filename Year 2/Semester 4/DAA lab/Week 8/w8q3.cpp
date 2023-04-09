#include <iostream>
#define MAX 100
using namespace std;
int graph[MAX][MAX];
bool visited[MAX];
int ind = 0,n;
int visitingOrd[MAX];

void dfs(int u)
{
    visited[u] = true;
    for (int i = 0; i < n; i++)
    {
        if (graph[u][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
    visitingOrd[ind++] = u;
}
void topologicalSort()
{
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    cout << "tasks based on dependency : \n";
    for (int i =ind-1; i >= 0; i--)
    {
        cout << visitingOrd[i] << " ";
    }
    cout << endl;
}
void checkDependency(){
    int u,v;
    cout<<"Enter two teams :\n";
    cin>>u,v;
    if(graph[u][v] || graph[v][u])
    cout<<"There is dependency \n";
    else
    cout<<"There is no dependency \n";
}
int main()
{
    int m, u, v;
    cout << "enter the no of teams : \n";
    cin >> n;
    cout << "Enter no of teams whose task are dependent :\n";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "enter 2 teams whose task are dependent :\n";
        cin >> u >> v;
        graph[u][v] = 1;
    }
    topologicalSort();
}