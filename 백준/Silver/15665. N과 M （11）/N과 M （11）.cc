#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int ans[10];

void permut(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!(num[i] == 0)) {
			ans[k] = num[i];
			permut(k + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	
	for (int i = 0; i < n; i++)
	{
		if (num[i] == num[i + 1])
		{
			int k = i+1;
			while (num[i] == num[k])
			{
				num[k] = 0;
				k++;
			}
			i = k-1;
		}
	}

	permut(0);
}