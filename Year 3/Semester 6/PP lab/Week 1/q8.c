#include <stdio.h>
// !Incomplete

int main() {
	int m[100][100], res[100][100], ress[100][100];
	int m1, m2;
	
	printf("Enter mat dims\n");
	scanf("%d%d", &m1, &m2);
	
	printf("Enter matrix\n");
	int i,j,k;
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
       		if (i == 0 || i == m1 - 1 || j == 0 || j == m2 -1) {
       		   res[i][j] = m[i][j];	
			} else {
				res[i][j] = ~m[i][j];
			}
		}
	}
	
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
       		if (i == 0 || i == m1 - 1 || j == 0 || j == m2 -1) {
       		   ress[i][j] = m[i][j];	
			} else {
				ress[i][j] = ~m[i][j];
			}
		}
	}
	
	printf("Result\n");
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
	return 0; 
}


