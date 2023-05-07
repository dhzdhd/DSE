// Knapsack 0/1

#include<iostream>
using namespace std;
#define max 100

int weights[max];
int values[max];
int n;
int w;
int **f = new int *[n+1];

int maxi(int a, int b){
    int maxi = a > b ? a : b;
    return maxi;
}

void funcIni(){
    for(int i = 0; i<n+1; i++){
        f[i] = new int[w+1];
    }

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<w+1; j++){
            if(i==0 || j==0) f[i][j] = 0;
            else f[i][j] = -1;
        }
    }
}
int knapsack() {
    int dp[n+1][w+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i-1] <= j) {
                dp[i][j] = maxi(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}

int main(){
    cout << "Enter the number of items \n";
    cin >> n;

    for(int i = 0; i<n; i++){
        cout << "Enter the weight and values of the item " << i+1 << "\n";
        cin >> weights[i] >> values[i];
    }

    cout << "Enter the capacity of the knapsack \n";
    cin >> w;
    cout << "Max value: \n"<<knapsack();

    return 0;
}
