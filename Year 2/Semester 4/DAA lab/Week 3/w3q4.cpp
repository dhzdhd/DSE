#include <iostream>
using namespace std;

int main() {
	int m, n, p, mat1[100][100], mat2[100][100], res[100][100];
	cout << "Enter dimensions of first matrix\n";
	cin >> m;
	cin >> n;
	
	cout << "Enter second dimension of second matrix\n";
	cin >> p;
	
	cout << "Enter elements of first matrix\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat1[i][j];
		}
	}
	
	cout << "Enter elements of second matrix\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> mat2[i][j];
		}
	}
	
	int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
	
	cout << "Resultant matrix\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
