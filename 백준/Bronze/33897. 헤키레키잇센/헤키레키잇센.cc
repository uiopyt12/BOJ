#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int pre, now, mxStereak = 1, nowSterak = 1, cnt = 1;
	cin >> pre;
	for (int i = 0; i < n-1; i++)
	{
		cin >> now;
		if (pre <= now)
			nowSterak++;
		else
		{
			cnt++;
			nowSterak = 1;
		}
		mxStereak = max(mxStereak, nowSterak);
		pre = now;
	}
	cout << cnt << ' ' << mxStereak;
}