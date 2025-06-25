#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


char tmp[51];
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
		printf("SK");
	else
		printf("CY");
}