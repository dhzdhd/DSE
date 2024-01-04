#include <stdio.h>

int main() {
	char str[100];
		 
    gets(str);
	
	char i = 0;
	while (str[i] != '\0') {
		  str[i] = (int)str[i] < 91 ? (char)((int)str[i] + 32): (char)((int)str[i] - 32);
		  i++;
	}
	printf("%s\n", str);
	
	return 0;
}

