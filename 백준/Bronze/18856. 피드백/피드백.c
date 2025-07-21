#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n-1; i++) {
		printf("%d ", i+1);
	}
	printf("997\n");

	return 0;
}