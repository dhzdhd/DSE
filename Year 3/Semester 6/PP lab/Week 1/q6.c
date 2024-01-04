#include <stdio.h>

int main() {
	int m[100][100], v[100][100],res[100][100];
	int m1, m2, v1,v2;
	
	printf("Enter mat dims\n");
	scanf("%d%d", &m1, &m2);
	printf("Enter vec dims\n");
	scanf("%d%d", &v1, &v2);
	
	if (m2 != v1) {
		printf("Can't multiply\n");
		return 0;
	}
	
	printf("Enter matrix\n");
	int i,j,k;
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	
	printf("Enter vec\n");
	for (i = 0; i < v1; i++) {
		for (j = 0; j < v2; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	
	for (i = 0; i < m1; i++) {
		for (j = 0; j < m2; j++) {
			res[i][j] = 0;
		}
	}
	
	for (i = 0; i < m1; i++) {
		for (j = 0; j < v2; j++) {
			for (k = 0; k < m2; k++) {
				res[i][j] += m[i][k] * v[k][j];
			}
		}
	}	
	
	printf("Result\n");
	for (i = 0; i < m1; i++) {
		for (j = 0; j < v2; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	return 0;
}

