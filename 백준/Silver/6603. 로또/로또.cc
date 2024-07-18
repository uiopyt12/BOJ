#include <bits/stdc++.h>
using namespace std;

int n;
int num[15];
int ans[6];
bool isUsed[15];

void permut(int level, int start)
{
	if (level == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (isUsed[i] == true) continue;
		ans[level] = num[i];
		isUsed[i] = true;
		permut(level + 1, i);
		isUsed[i] = false;
	}
}

int main()
{
	do
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		permut(0, 0);
		cout << '\n';
	} while (n != 0);	
}