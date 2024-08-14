#include <bits/stdc++.h>
using namespace std;

int heap[100001]; // 부모 자식 계산의 편의를 위해 1-index 사용
int heapIDX; // 힙의 크기이자, 마지막으로 삽입된 원소를 가리키고 있음

void push(int n)
{
	heap[++heapIDX] = n;
	
	int childIDX = heapIDX;
	int parentIDX = heapIDX / 2;
	while (heap[childIDX] < heap[parentIDX]) // 최소 힙이므로 부모가 자식보다 작아야 함
	{
		swap(heap[childIDX], heap[parentIDX]);
		if (parentIDX == 1) break;
		childIDX /= 2;
		parentIDX /= 2;
	}
}

int top()
{
	if (heapIDX == 0) return 0;
	return heap[1];
}

void pop()
{
	if (heapIDX == 0) // 힙의 크기가 0이면 반환
		return;
	swap(heap[1], heap[heapIDX]); // 마지막 원소랑 루트랑 자리를 바꿈
	heapIDX--; // 힙의 크기를 감소시키고, 마지막으로 삽입된 원소를 가리키게 함
	
	int parentIDX = 1;
	while (parentIDX*2 <= heapIDX) // 왼쪽 자식이 있는 동안
	{
		int minChildIDX = parentIDX * 2; 
		if (minChildIDX + 1 <= heapIDX && heap[minChildIDX] > heap[minChildIDX + 1])
			minChildIDX += 1;
		if (heap[minChildIDX] >= heap[parentIDX]) break;
		swap(heap[parentIDX], heap[minChildIDX]);
		parentIDX = minChildIDX;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x != 0)
		{
			push(x);
		}
		else 
		{
			cout << top() << '\n';
			pop();
		}
	}
}