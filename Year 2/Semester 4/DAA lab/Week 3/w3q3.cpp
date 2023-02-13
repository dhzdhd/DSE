#include <iostream>
using namespace std;

int length(char text[]) {
	int c = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		c++;
	}
	return c;
}

int main() {
	char text[100];
	char pattern[100];
	
	cout << "Enter text and pattern\n";
	gets(text);
	gets(pattern);
	
	int n = length(text);
	int m = length(pattern);
	
	int index = -1;
	for (int i = 0; i <= n-m; i++) {
		int j = 0;
		while (j < m && pattern[j] == text[i + j]) {
			j++;
		}
		if (j == m) {
			index = i;
			break;
		}
	}
	
	cout << index << endl;
	
	return 0;
}
