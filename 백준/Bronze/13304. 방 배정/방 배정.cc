#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n, k, s, y;
	scanf("%d %d", &n, &k);

	int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
	// r1은 room1의 줄임말로, r1은 1~2학년의 총 학생
	// r2는 3~4학년 남학생, r3는 3~4학년 여학생
	// r3는 5~6학년 남학생, r5는 5~6학년 여학생
	// 의 수를 나타낸 변수

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &s, &y);
		if (y <= 2)
			r1++;
		else if ((y <= 4) && (s == 1))
			r2++;
		else if ((y <= 4) && (s == 0))
			r3++;
		else if ((s == 1))
			r4++;
		else if (s == 0)
			r5++;
		else
			printf("how");
	}

	int room = 0;
	if ((r1 % k == 0))
		room += r1 / k;
	else
		room += (r1 / k) + 1;
	if ((r2 % k == 0))
		room += r2 / k;
	else
		room += (r2 / k) + 1;
	if ((r3 % k == 0))
		room += r3 / k;
	else
		room += (r3 / k) + 1;
	if ((r4 % k == 0))
		room += r4 / k;
	else
		room += (r4 / k) + 1;
	if ((r5 % k == 0))
		room += r5 / k;
	else
		room += (r5 / k) + 1;

	printf("%d", room);

}