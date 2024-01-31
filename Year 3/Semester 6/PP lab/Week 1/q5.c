// Intercalate strings

#include <stdio.h>

int main()
{
	char str1[100], str2[100];

	printf("Enter 2 strings\n");

	gets(str1);
	gets(str2);

	char buf[100];

	int i = 0;
	int ctr = 0;
	while (str1[i] != '\0')
	{
		buf[ctr] = str1[i];
		ctr++;
		buf[ctr] = str2[i];
		i++;
		ctr++;
	}
	i = 0;
	printf("%s\n", buf);

	return 0;
}
