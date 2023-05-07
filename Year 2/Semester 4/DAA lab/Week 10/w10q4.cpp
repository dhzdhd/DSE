// Knapsack 0/1

#include <iostream>
using namespace std;

int mfks(int i, int W, int *weights, int *values, int matrix[100][100]) {
    if (matrix[i][W] < 0) {
        int value;
        if (W < weights[i]) {
            value = mfks(i - 1, W, weights, values, matrix);
        } else {
            value = max(
                mfks(i - 1, W, weights, values, matrix),
                values[i] + mfks(i - 1, W - weights[i], weights, values, matrix)
            );
        }

        matrix[i][W] = value;
    }
    return mfks(i, W, weights, values, matrix);
}

int main() {
    int matrix[100][100];
    int n, W;

    cout << "Enter number of values & knapsack capacity\n";
    cin >> n >> W;

    int *weights = new int[n];
    int *values = new int[n];

    cout << "Enter weights and values\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];

        for (int j = 0; j < W; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    mfks(n - 1, W, weights, values, matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
