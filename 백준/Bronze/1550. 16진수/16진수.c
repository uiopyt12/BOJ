#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char hexa[7];
	scanf("%s", hexa);

	int idx = 0;
	for (int i = 0; i < 7; i++) {
		if (hexa[i] == '\0')
			break;
		idx++;
	}
	idx--;
	int multiplier = -1;
	int num;
	int deci = 0;
	for (int i = idx; i >= 0; i--) {
		if (hexa[i] >= 'A')
			num = (int)(hexa[i] - 'A' + 10);
		else
			num = (int)(hexa[i] - '0');
		multiplier++;
		for (int i = 0; i < multiplier; i++) {
			num *= 16;
		}
		deci += num;
	}

	printf("%d", deci);

	return 0;
}