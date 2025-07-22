#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int vote[51]; // 1-index
int arrMax(int size) // 배열의 최대값이 몇번째에 있는지, 인덱스를 반환하는 함수
{
	int maxIdx = 1;
	for (int i = 2; i <= size; i++) {
		if (vote[maxIdx] <= vote[i])
			maxIdx = i;
	}
	return maxIdx;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &vote[i]);

	int buyPeople = 0;
	int maxIdx = arrMax(n);
	while (maxIdx != 1) {
		vote[maxIdx]--; 
		vote[1]++; // 다솜은 기호 1번
		buyPeople++;
		maxIdx = arrMax(n);
	}

	printf("%d", buyPeople);

	return 0;
}