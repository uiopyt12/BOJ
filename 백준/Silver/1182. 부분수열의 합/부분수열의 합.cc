#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int num[21];
int idx;

void subsqnc(int sum)
{
	if (idx == n)
	{
		if (sum == s) cnt++;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		
		if (i == 0) // i가 0이면 더해주고, 1이면 더하지 않음
		{
			sum += num[idx];
			idx++;
			subsqnc(sum);
			idx--;
			sum -= num[idx];
		}
		else if (i == 1)
		{
			idx++;
			subsqnc(sum);
			idx--;
		}

	}
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	subsqnc(0);
	if (s == 0) cnt--;
	cout << cnt;
}