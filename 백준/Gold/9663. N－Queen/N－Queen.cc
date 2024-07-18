#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool col[16];
bool diag1[32]; //  '\' 방향 대각선	cur과 i의 차가 동일한 성질이 있다.
bool diag2[32]; //  '/' 방향 대각선	cur과 i의 합이 동일한 성질이 있다.

void nQueen(int cur)
{
	if (cur == n)
	{
		cnt++;
		return; // base case
	}

	for (int i = 0; i < n; i++)  // 하나의 행에는 하나의 퀸만 놓을 수 있기 때문에 cur을 하나씩 증가시키며 [cur행], [i열]을 검사
	{
		if ((col[i] == true) || (diag1[cur - i + n] == true) || (diag2[cur + i]) == true) continue; // 상수 시간에 퀸을 놓을 수 있는 지 검사
		col[i] = true;
		diag1[cur - i + n] = true;
		diag2[cur + i] = true;
		nQueen(cur + 1); 
		col[i] = false;
		diag1[cur - i + n] = false;
		diag2[cur + i] = false;
	}

}

int main()
{
	cin >> n;
	nQueen(0);
	cout << cnt;
}