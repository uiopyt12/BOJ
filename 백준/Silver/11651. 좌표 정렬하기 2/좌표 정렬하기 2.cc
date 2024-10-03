#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v1(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i].first >> v1[i].second;
	}

	sort(v1.begin(), v1.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << v1[i].first << ' ' << v1[i].second << '\n';
	}
}