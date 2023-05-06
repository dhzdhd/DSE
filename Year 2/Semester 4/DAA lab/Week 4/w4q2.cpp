// Assignment problem

#include <iostream>
using namespace std;

int N;
int cost[10][10];
int permutation[10];
int bestCost = 2147483647;
int bestPermutation[10];

void generatePermutations(int depth)
{
    if (depth == N)
    {
        int currentCost = 0;
        for (int i = 0; i < N; i++)
        {
            currentCost += cost[i][permutation[i]];
        }
        if (currentCost < bestCost)
        {
            bestCost = currentCost;
            for (int i = 0; i < N; i++)
            {
                bestPermutation[i] = permutation[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            bool used = false;
            for (int j = 0; j < depth; j++)
            {
                if (permutation[j] == i)
                {
                    used = true;
                    break;
                }
            }
            if (!used)
            {
                permutation[depth] = i;
                generatePermutations(depth + 1);
            }
        }
    }
}

int main()
{
    cout << "Enter number of jobs\n";
    cin >> N;

    cout << "Enter costs\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }
    generatePermutations(0);
    cout << "Best cost: " << bestCost << endl;
    cout << "Best permutation: ";
    for (int i = 0; i < N; i++)
    {
        cout << bestPermutation[i] << " ";
    }
    cout << endl;
    return 0;
}
