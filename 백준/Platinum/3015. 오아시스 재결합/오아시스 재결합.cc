#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair <int, int>> st;
	vector<int> v(n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v[n-1 - i] = tmp;

		while (!st.empty() && st.top().first < tmp)
		{
			long long freq = st.top().second;
			ans += freq;
			ans += freq * (freq - 1) / 2;
			st.pop();
		}
		if (!st.empty() && st.top().first == tmp) 
			st.top().second++;
		else st.push({ tmp,1 });
	}
	while (!st.empty())
	{
		if (st.top().second != 1)
		{
			long long freq = st.top().second;
			ans += freq * (freq - 1) / 2;
		}
		st.pop();
	}

	stack<int> st2;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		tmp = v[i];

		while (!st2.empty() && st2.top() < tmp)
		{
			ans++;
			st2.pop();
		}
		if (st2.empty()) st2.push(tmp);
		else if (st2.top() >= tmp) st2.push(tmp);
	}

	cout << ans;

}