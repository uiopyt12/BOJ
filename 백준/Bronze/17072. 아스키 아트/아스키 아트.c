#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char art[401][401];

int main()
{
	int n, m;
	int r, g, b;
	unsigned int exp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &r, &g, &b);
			exp = 2126 * r + 7152 * g + 722 * b;
			if (exp < 510000)
				art[i][j] = '#';
			else if (exp >= 510000 && exp < 1020000)
				art[i][j] = 'o';
			else if (exp >= 1020000 && exp < 1530000)
				art[i][j] = '+';
			else if (exp >= 1530000 && exp < 2040000)
				art[i][j] = '-';
			else if (exp >= 2040000)
				art[i][j] = '.';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", art[i][j]);
		}
		printf("\n");
	}


	return 0;
}