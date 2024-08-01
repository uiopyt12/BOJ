#include <bits/stdc++.h>
using namespace std;

int building[1000001];

int main()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	building[s] = 1;

	queue <int> q;
	int cur;
	q.push(s);
	while (!q.empty())
	{
		cur = q.front(); q.pop();
		if (cur == g) break;
		for (int i = 0; i < 2; i++)
		{
			int delta = (i == 0) ? u : -d; // delta값은 0이면 u, 1이면 d
			int newC = cur + delta;
			if (newC > f) continue;
			if (newC < 1) continue;
			if (building[newC] != 0) continue; // 이미 방문한 곳이면 건너뜀
			building[newC] = building[cur] + 1;
			q.push(newC);
		}
	}

	if (building[g] == 0) cout << "use the stairs";
	else cout << building[g]-1;


}