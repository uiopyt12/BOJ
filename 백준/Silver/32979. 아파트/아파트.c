#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int q[81];

int main()
{
	int n, t;
	scanf("%d\n%d", &n, &t);

	int size = 2 * n;
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &q[i]);
	}


	int accumulateT = 0;
	int call;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &call);
		accumulateT += call-1;
		accumulateT %= size;
		printf("%d ", q[accumulateT]);
	}

}