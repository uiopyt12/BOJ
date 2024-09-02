#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	cin >> m;
	int tmp;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (binary_search(a.begin(), a.end(), tmp) == true)
		{
			cout << 1 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	

}