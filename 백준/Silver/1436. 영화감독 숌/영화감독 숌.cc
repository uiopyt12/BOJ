#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main()
{


	int n;
	cin >> n;
	string s;

	int idx = 1;
	for (int i = 666; i < INT_MAX; i++)
	{
		if (a[n] != 0) break;
		s = to_string(i);
		int streak = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '6')
				streak++;
			else
				streak = 0;

			if (streak == 3)
			{
				a[idx] = i;
				idx++;
			}
		}
	}
	cout << a[n];
}