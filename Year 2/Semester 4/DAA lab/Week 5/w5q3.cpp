#include <iostream>
using namespace std;

int countt;

struct QueueRepr
{
    int queue[100];
    int maxSize;
    int front;
    int rear;
};

bool isEmpty(QueueRepr *inst)
{
    return inst->front == inst->rear;
}

bool isFull(QueueRepr *inst)
{
    return inst->rear == inst->maxSize;
}

void enqueue(QueueRepr *inst, int element)
{
    if (isFull(inst))
    {
        cout << "Overflow!\n";
        return;
    }

    inst->queue[inst->rear++] = element;
}

void dequeue(QueueRepr *inst)
{
    if (isEmpty(inst))
    {
        cout << "Underflow!\n";
        return;
    }

    inst->front++;
}

int front(QueueRepr *inst)
{
    return inst->queue[inst->rear - 1];
}

void bfs(int v, int n, int *visited, int **graph)
{
    countt++;
    visited[v] = countt;

    QueueRepr queue;
    queue.maxSize = n;
    queue.front = 0;
    queue.rear = 0;

    enqueue(&queue, v);

    while (!isEmpty(&queue))
    {
        for (int i = 0; i < n; i++)
        {
            int frt = front(&queue);
            if (graph[frt][i] == 1 && visited[i] == 0)
            {
                countt++;
                visited[i] = countt;
                enqueue(&queue, i);
            }
        }
        dequeue(&queue);
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

    countt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i, n, visited, graph);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << visited[i] - 1 << " ";
    }
    cout << endl;

    return 0;
}
