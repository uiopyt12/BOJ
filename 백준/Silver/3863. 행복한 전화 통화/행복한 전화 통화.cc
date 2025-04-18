#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n=1, m;

	int src, dest, start, dura;
	int cnt;
	while (n != 0)
	{
		vector <pair<int, int>> vec;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> src >> dest >> start >> dura;
			vec.push_back({ start, start+dura });
		}
		for (int i = 0; i < m; i++)
		{
			cin >> start >> dura;
			cnt = 0;
			for (const auto& i : vec)
			{
				if (!(((start < i.first) && (start+dura <= i.first)) || (start >= i.second)))
				{
					cnt++;
				}
			}
			cout << cnt << '\n';
		}


	}
}