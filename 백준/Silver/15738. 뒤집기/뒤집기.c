#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);

	int tmp;
	for (int i = 0; i < n; i++)
		scanf("%d ", &tmp);

	int calc;
	int idx = k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &calc);
		if (calc > 0) // 연산이 양수인 경우
		{
			if (idx <= calc)
			{
				idx = (calc + 1) - idx;
			}
		}
		else // 연산이 음수인 경우
		{
			int offset = n + calc;
			if (n + calc + 1 <= idx)
			{
				idx -= offset;
				idx = (calc*-1) + 1 - idx;
				idx += offset;
			}
		}
	}

	printf("%d", idx);

	return 0;
}