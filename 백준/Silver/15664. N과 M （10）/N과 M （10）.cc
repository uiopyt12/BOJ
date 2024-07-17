#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[10];
int num[10]; 
int freq[10]; // 0 to 9

void permut(int level, int last)
{
	if (level == m)
	{
		for (int i = 0; i < level; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < 10; i++)
	{
		if (num[i] < last) continue;
		if (freq[i] == 0) continue;
		ans[level] = num[i];
		freq[i]--;
		permut(level + 1, num[i]);
		freq[i]++;
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
		if (num[i] == 0) break;
		freq[i]++;
		if (num[i] == num[i + 1])
		{
			int k = i;
			while (num[k] == num[k + 1])
			{
				k++;
				freq[i]++;
			}
			i = k;
		}
	}

	permut(0, 0);
}