#include <iostream>
using namespace std;


void hanoi(int n, int start, int end)
{
	if (n == 1) // base 
		cout << start << ' ' << end << '\n';
	else
	{
		hanoi(n - 1, start, 6 - start - end); // 1, 3, 7, 15, ...
		cout << start << ' ' << end << '\n'; // 1 (n번째로 작은 원판 이동)
		hanoi(n - 1, 6 - start - end, end); // 1, 3, 7, 15, ...
	}

	// 장대를 1, 2, 3으로 생각했을 때 이를 모두 더하면 6이므로 6-start-end는 start도 end도 아닌 장대를 의미
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 3);
}

// 원판 1개 일 때 옮길 수 있다.
// 원판이 2개일 때에도 옮길 수 있다. (제일 작은 원판을 start도 end도 아닌 곳에 보관해두었다가 end로 옮기면 됨)
// 원판이 3개일 때에도 옮길 수 있다. (원판 2개를 start도 end도 아닌 곳에 보관해두었다가 end로 옮기면 됨)
// 원판이 k+1일 때에도 옮길 수 있다. (원판 k개를 start도 end도 아닌 곳에 보관해두었다가 end로 옮기면 됨)