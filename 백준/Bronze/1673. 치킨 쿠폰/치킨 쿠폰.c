#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int k, n;
	int coupon;
	int canChicken;
	while (scanf("%d %d", &k, &n) == 2)
	{
		coupon = k;
		canChicken = k;

		while (coupon >= n)
		{
			int tmp = coupon / n;
			canChicken += tmp;
			coupon -= tmp * n;
			coupon += tmp;
		}
		printf("%d\n", canChicken);
	}

}