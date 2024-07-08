#include <bits/stdc++.h>
using namespace std;

long cnt = 0;
void Z(int n, int r, int c)
{
	if (r < pow(2, (n-1)) && c < pow(2, (n-1)) ) // 0
	{
		if (n == 1) cout << cnt;
		else
		{
			Z(n - 1, r, c);
		}
	}
	else if (r < pow(2, (n-1)) && c >= pow(2, (n-1))) // 1
	{
		if (n == 1) 
		{
			cnt += 1;
			cout << cnt;
		}
		else
		{
			cnt += pow(2, (n-1)*2);
			Z(n - 1, r, c - pow(2, (n - 1)));
		}
	}
	else if (r >= pow(2, (n-1)) && c < pow(2, (n-1))) // 2
	{
		if (n == 1)
		{
			cnt += 2;
			cout << cnt;
		}
		else
		{
			cnt += pow(2, (n - 1) * 2) * 2;
			Z(n - 1, r - pow(2, (n - 1)), c);
		}
	}
	else if (r >= pow(2, (n-1)) && c >= pow(2, (n-1))) // 3
	{
		if (n == 1)
		{
			cnt += 3;
			cout << cnt;
		}
		else
		{
			cnt += pow(2, (n - 1) * 2) * 3;
			Z(n - 1, r - pow(2, (n - 1)), c - pow(2, (n - 1)));
		}
	}	
		

}


int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	Z(n, r, c);

	
}

// 비트쉬프트를 통한 거듭제곱은 0승을 표현하지 못함