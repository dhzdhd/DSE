#include <iostream>
using namespace std;

int get_len(char str[50]) {
	int count = 0;
	while(str[count] != '\0') {
		count++;
	}
	return count;
}

int delete_(char str[50], char sub[50]) {
	char new_str[50];

//	int j = 0, counter = 0;
//	for (int i = 0; str[i] != '\0'; i++) {
//		if (str[i] == ' ' && str[i+1] != ' ') {
//			matrix[counter][j] = '\0';
//			counter++;
//			j = 0;
//		}
//		matrix[counter][j] = str[i];
//		j++;
//	}
	
	int sub_length = get_len(sub);

	int k = 0;
	int buffer = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (i == sub[0]) {
			buffer = i;
			for (int k = i; str[k] == sub[i + k]; k++) {
				
			}
		}
	}

	for (int i = 0; i < counter; i++) {
		cout << matrix[counter] << "\n";
	}

}

int main() {
	char str[50];
	char sub_str[50];
	int index;

	cout << "Enter the first string\n";
	gets(str);
	cout << "Enter the sub string\n";
	gets(sub_str);
	
	delete_(str, sub_str);

	return 0;
}
