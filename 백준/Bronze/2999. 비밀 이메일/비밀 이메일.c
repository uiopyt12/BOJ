#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)

int main()
{
	char str1[101] = { 0 };
	scanf("%s", str1);

	int n = strlen(str1);
	int r = 0;
	int mn;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			mn = min(n/i, i);
			r = max(mn, r);
		}
	}
	int c = n / r;
	int idx = 0;
	char str2[101][101] = { 0 };
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			str2[j][i] = str1[idx++];
		}
	}
	char str3[101] = { 0 };
	idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			str3[idx++] = str2[i][j];
		}
	}

	printf("%s", str3);
}