// Knapsack

#include <iostream>
using namespace std;

struct Item
{
    int weight;
    int value;
};

int N;
int W;
Item items[100];
int bestValue = 0;
bool bestItems[100];

void generateSubsets(int depth, int currentWeight, int currentValue, bool currentItems[])
{
    if (depth == N)
    {
        if (currentValue > bestValue)
        {
            bestValue = currentValue;
            for (int i = 0; i < N; i++)
            {
                bestItems[i] = currentItems[i];
            }
        }
    }
    else
    {
        if (currentWeight + items[depth].weight <= W)
        {
            currentItems[depth] = true;
            generateSubsets(depth + 1, currentWeight + items[depth].weight, currentValue + items[depth].value, currentItems);
        }
        currentItems[depth] = false;
        generateSubsets(depth + 1, currentWeight, currentValue, currentItems);
    }
}

int main()
{
    cout << "Enter number of items and max knapsack weight\n";
    cin >> N >> W;

    cout << "Enter weights and values\n";
    for (int i = 0; i < N; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }

    bool currentItems[100] = {false};
    generateSubsets(0, 0, 0, currentItems);

    cout << "Maximum value: " << bestValue << endl;
    cout << "Items included: ";

    for (int i = 0; i < N; i++)
    {
        if (bestItems[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
