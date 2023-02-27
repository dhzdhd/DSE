#include <iostream>
using namespace std;

const int MAX_N = 10; // maximum size of the cost matrix

int N; // number of rows and columns in the cost matrix
int cost[MAX_N][MAX_N]; // the cost matrix
int permutation[MAX_N]; // current permutation being generated
int bestCost = 2147483647; // best cost found so far
int bestPermutation[MAX_N]; // best permutation found so far

// Recursive function to generate all permutations
void generatePermutations(int depth) {
    if (depth == N) {
        int currentCost = 0;
        for (int i = 0; i < N; i++) {
            currentCost += cost[i][permutation[i]];
        }
        if (currentCost < bestCost) {
            bestCost = currentCost;
            for (int i = 0; i < N; i++) {
                bestPermutation[i] = permutation[i];
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            bool used = false;
            for (int j = 0; j < depth; j++) {
                if (permutation[j] == i) {
                    used = true;
                    break;
                }
            }
            if (!used) {
                permutation[depth] = i;
                generatePermutations(depth + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    generatePermutations(0);
    cout << "Best cost: " << bestCost << endl;
    cout << "Best permutation: ";
    for (int i = 0; i < N; i++) {
        cout << bestPermutation[i] << " ";
    }
    cout << endl;
    return 0;
}
