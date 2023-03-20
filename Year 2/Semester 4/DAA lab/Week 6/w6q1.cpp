// Topological sort

#include <iostream>
using namespace std;

int count;

struct StackRepr
{
    int stack[100];
    int top;
};

bool isEmpty(StackRepr &inst)
{
    return inst.top == 0;
}

void push(StackRepr &inst, int value)
{
    inst.stack[inst.top] = value;
    inst.top++;
}

int pop(StackRepr &inst)
{
    --inst.top;
    return inst.stack[inst.top];
    // inst.stack[--inst.top];
}

int peek(StackRepr &inst)
{
    return inst.stack[inst.top - 1];
}

void dfs(int v, int n, int *visited, int **graph, int *popping)
{
    StackRepr stack;
    stack.top = 0;

    push(stack, v);

    int c = 0;
    while (!isEmpty(stack))
    {
        for (int i = 0; i < n; i++)
        {
            int frt = peek(stack);
            if (graph[frt][i] == 1 && visited[i] == 0)
            {
                count++;
                visited[i] = count;
                push(stack, i);
            }
        }
        popping[c++] = pop(stack);
    }
}

int main()
{
    int n;

    cout << "Enter size of matrix\n";
    cin >> n;

    int **graph = new int *[n];
    int *visited = new int[n];
    int *popping = new int[n];

    cout << "Enter edges per indices, 1 for edge, 0 for no edge\n";
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cout << "i " << i << " | j " << j << "  ";
            cin >> graph[i][j];
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
            dfs(i, n, visited, graph, popping);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << popping[n - i - 1] << "->";
    }
    cout << endl;

    return 0;
}
