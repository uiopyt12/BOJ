#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	char arr[14]; // C언어는 문자열의 끝을 널문자로 확인하기 때문에 14개 할당
	scanf("%s", arr);

	int x, xIdx; // x는 *로 된 자리의 미지수, xIdx는 1 또는 3으로 x에 곱해질 계수
	int sum = 0;
	for (int i = 0; i < 13; i++) // 체크기호 상관하지 않고 미지수까지 한번에 모두 더해줌
	{
		if (arr[i] == '*')
		{
			xIdx = i;
			continue;
		}
		if ((i % 2) == 0)
		{
			sum += arr[i] - '0';
		}
		else
		{
			sum += (arr[i] - '0') * 3;
		}
	}
	if (xIdx % 2 == 0) // 더해질 계수 결정, 짝수번째 자리면 1, 홀수번째 자리면 3
		xIdx = 1;
	else
		xIdx = 3;

	for (int i = 0; i < 10; i++) // 0부터 9까지 어떤 수를 넣었을 때 0이 되는 지 확인
	{
		if ((i * xIdx + sum) % 10 == 0)
		{
			x = i;
		}
	}
	printf("%d\n", x);

	return 0;
}