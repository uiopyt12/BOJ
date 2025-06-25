#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void decalcomani(char src[], int size)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		if (src[start] != '.')
			src[end] = src[start];
		else if (src[end] != '.')
			src[start] = src[end];
		start++, end--;
	}
	printf("%s\n", src);

	return;
}

char tmp[51];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[j] = '.';
		}
		scanf("%s", tmp);
		tmp[m] = '\0';
		decalcomani(tmp, m);
	}

	return 0;
}