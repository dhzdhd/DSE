// Binomial coefficient

#include<iostream>
using namespace std;

int min(int a,int b){
    int min = (a<b) ? a : b;
    return min;
}

int binomialCoeff(int n,int k){
    int c[n+1][k+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < k+1; j++){
            c[i][j] = 0;
        }
    }

    for(int i =0;i<n;i++){
        for(int j = 0; j < min(i,k); j++){
            if(j==0 || j==1){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
}

int main(){
    int n, k;
    cout << "Enter n and k :\n";
    cin >> n >> k;
    cout << "Binomial Coefficient is :"<<binomialCoeff(n,k);

    return 0;
}
