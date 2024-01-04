#include <stdio.h>

int main() {
	int a, b;
	char op;
	
	printf("Enter op, num, num\n");
	scanf("%c", &op);
	scanf("%d%d", &a, &b);
	
	switch (op) {
		   case '+': printf("%d", a + b); break;
		   case '-': printf("%d", a - b); break;
		   case '*': printf("%d", a * b); break;
		   case '/': printf("%d", a / b); break;
		   default: printf("Wrong operator"); break;
	}
	
	return 0;
}

