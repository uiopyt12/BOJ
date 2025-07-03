#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int64_t pow[64];
int main()
{
	int t;
	scanf("%d", &t);
	int64_t n, a, b;
	for (int i = 0; i < 63; i++)
		pow[i] = (int64_t)1 << i;

	for (int i = 0; i < t; i++)
	{
		scanf("%lld %lld %lld", &n, &a, &b);
		for (int i = 0; i < n; i++)
		{
			if ((a & pow[i]) != 0)
			{
				printf("%d\n", n - i);
				break;
			}
		}
	}

	return 0;
}