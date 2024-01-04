#include <stdio.h>

int main() {
	int n;
	printf("Enter num\n");
	scanf("%d", &n);
	
	int i = 0;
	char str[] = "PCBD";
	for (; i < n; i++) {
		int j = 0;
		for (; j <= i; j++) {
			printf("%c", str[i % 4]);
		}
	}
}

