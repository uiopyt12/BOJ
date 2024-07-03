#include <bits/stdc++.h>
using namespace std;

int vis[300][300];
int dx[8] = { 2, 2, 1, -1, -2, -2, -1, 1 }; // Knight's movement
int dy[8] = { 1, -1, -2 , -2, -1, 1, 2, 2 };


int main()
{
	int tc, l;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> l;

		queue<pair<int, int>> q;
		while (!q.empty())
			q.pop();
		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		q.push(start);
		vis[start.first][start.second] = 1;
		
		

		while (!q.empty())
		{
			pair <int, int> cur = q.front(); q.pop();
			if (cur.first == end.first && cur.second == end.second)
			{
				cout << vis[cur.first][cur.second]-1 << endl;
				break;
			}
				
			for (int mv = 0; mv < 8; mv++)
			{
				int ny = cur.first + dy[mv];
				int nx = cur.second + dx[mv];
				if (ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
				if (vis[ny][nx] != 0) continue;

				// move and check is end
				vis[ny][nx] = vis[cur.first][cur.second] + 1;
				q.push({ ny, nx });
			}
		}

		for (int j = 0; j < l; j++)
			fill(vis[0], vis[j] + 300, 0);

	}


	return 0;
}
