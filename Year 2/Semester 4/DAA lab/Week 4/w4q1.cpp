#include <iostream>
using namespace std;

const int MAX_N = 100; // maximum number of items
const int MAX_W = 1000; // maximum weight of the knapsack

struct Item {
    int weight;
    int value;
};

int N; // number of items
int W; // maximum weight of the knapsack
Item items[MAX_N]; // array of items
int bestValue = 0; // best value found so far
bool bestItems[MAX_N]; // which items are included in the best solution

// Recursive function to generate all subsets of items
void generateSubsets(int depth, int currentWeight, int currentValue, bool currentItems[]) {
    if (depth == N) {
        if (currentValue > bestValue) {
            bestValue = currentValue;
            for (int i = 0; i < N; i++) {
                bestItems[i] = currentItems[i];
            }
        }
    } else {
        // Include the current item
        if (currentWeight + items[depth].weight <= W) {
            currentItems[depth] = true;
            generateSubsets(depth + 1, currentWeight + items[depth].weight, currentValue + items[depth].value, currentItems);
        }
        // Exclude the current item
        currentItems[depth] = false;
        generateSubsets(depth + 1, currentWeight, currentValue, currentItems);
    }
}

int main() {
    cin >> N >> W;

    for (int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    bool currentItems[MAX_N] = {false};
    generateSubsets(0, 0, 0, currentItems);

    cout << "Maximum value: " << bestValue << endl;
    cout << "Items included: ";

    for (int i = 0; i < N; i++) {
        if (bestItems[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
