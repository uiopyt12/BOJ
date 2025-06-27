#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a) > (b) ? (b) : (a)) 

typedef struct studentInfo
{
	int studentID;
	int sub1;
	int sub2;
	int sub3;
	int sub4;
}studentInfo;

int compareById(const void* a, const void* b)
{
	studentInfo* pa = (studentInfo*)a;
	studentInfo* pb = (studentInfo*)b;

	if (pa->studentID > pb->studentID)
		return 1;
	else if (pa->studentID < pb->studentID)
		return -1;
	else
		return 0;
}

int compareBySub1(const void* a, const void* b)
{
	studentInfo* pa = (studentInfo*)a;
	studentInfo* pb = (studentInfo*)b;

	if (pa->sub1 > pb->sub1)
		return 1;
	else if (pa->sub1 < pb->sub1)
		return -1;
	else
		return 0;
}

int compareBySub2(const void* a, const void* b)
{
	studentInfo* pa = (studentInfo*)a;
	studentInfo* pb = (studentInfo*)b;

	if (pa->sub2 > pb->sub2)
		return 1;
	else if (pa->sub2 < pb->sub2)
		return -1;
	else
		return 0;
}

int compareBySub3(const void* a, const void* b)
{
	studentInfo* pa = (studentInfo*)a;
	studentInfo* pb = (studentInfo*)b;

	if (pa->sub3 > pb->sub3)
		return 1;
	else if (pa->sub3 < pb->sub3)
		return -1;
	else
		return 0;
}

int compareBySub4(const void* a, const void* b)
{
	studentInfo* pa = (studentInfo*)a;
	studentInfo* pb = (studentInfo*)b;

	if (pa->sub4 > pb->sub4)
		return 1;
	else if (pa->sub4 < pb->sub4)
		return -1;
	else
		return 0;
}



studentInfo arr[200001];
int main()
{
	int n;
	scanf("%d", &n);
	int prizeID;
	int x, a, b, c, d;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d %d", &arr[i].studentID, &arr[i].sub1, &arr[i].sub2, &arr[i].sub3, &arr[i].sub4);


	qsort(arr, n, sizeof(studentInfo), compareBySub1);
	prizeID = arr[n - 1].studentID;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i].sub1 == arr[i - 1].sub1)
			prizeID = min(prizeID, arr[i - 1].studentID);
		else
			break;
	}
	printf("%d ", prizeID);
	qsort(arr, n, sizeof(studentInfo), compareById);
	arr[prizeID - 1].sub1 = -1;
	arr[prizeID - 1].sub2 = -1;
	arr[prizeID - 1].sub3 = -1;
	arr[prizeID - 1].sub4 = -1;


	qsort(arr, n, sizeof(studentInfo), compareBySub2);
	prizeID = arr[n - 1].studentID;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i].sub2 == arr[i - 1].sub2)
			prizeID = min(prizeID, min(arr[i].studentID, arr[i - 1].studentID));
		else
			break;
	}
	printf("%d ", prizeID);
	qsort(arr, n, sizeof(studentInfo), compareById);
	arr[prizeID - 1].sub1 = -1;
	arr[prizeID - 1].sub2 = -1;
	arr[prizeID - 1].sub3 = -1;
	arr[prizeID - 1].sub4 = -1;


	qsort(arr, n, sizeof(studentInfo), compareBySub3);
	prizeID = arr[n - 1].studentID;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i].sub3 == arr[i - 1].sub3)
			prizeID = min(prizeID, min(arr[i].studentID, arr[i - 1].studentID));
		else
			break;
	}
	printf("%d ", prizeID);
	qsort(arr, n, sizeof(studentInfo), compareById);
	arr[prizeID - 1].sub1 = -1;
	arr[prizeID - 1].sub2 = -1;
	arr[prizeID - 1].sub3 = -1;
	arr[prizeID - 1].sub4 = -1;


	qsort(arr, n, sizeof(studentInfo), compareBySub4);
	prizeID = arr[n - 1].studentID;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i].sub4 == arr[i - 1].sub4)
			prizeID = min(prizeID, min(arr[i].studentID, arr[i - 1].studentID));
		else
			break;
	}
	printf("%d ", prizeID);
	qsort(arr, n, sizeof(studentInfo), compareById);
	arr[prizeID - 1].sub1 = -1;
	arr[prizeID - 1].sub2 = -1;
	arr[prizeID - 1].sub3 = -1;
	arr[prizeID - 1].sub4 = -1;
}