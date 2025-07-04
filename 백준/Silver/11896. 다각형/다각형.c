#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);

	if (a % 2 != 0)
		a++; 
	if (b % 2 != 0)
		b--;

	long long ans;
	if (a <= 2)
	{
		if (b < 4)
			ans = 0;
		else
			ans = (b / 2) * (b / 2 + 1) - 2;
	}
	else if (a == b)
	{
		ans = a;
	}
	else 
	{
		ans = (b/2) * (b/2+1) - (a/2-1) * (a/2);
	}
	printf("%lld", ans);


	return 0;
}