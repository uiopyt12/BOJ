#include <bits/stdc++.h>
#define y first
#define x second

using namespace std;

string maze[1001];
int human[1001][1001];
int fire[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };


int main()
{
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int w, h;
		cin >> w >> h;

		for (int i = 0; i < h; i++) // init
		{
			fill(human[i], human[i] + 1001, 0);
			fill(fire[i], fire[i] + 1001, 0);
		}

		for (int i = 0; i < h; i++)
		{
			cin >> maze[i];
		}



		queue<pair<int, int>> qHuman, qFire;
		while (!qHuman.empty())
			qHuman.pop();
		while (!qFire.empty())
			qFire.pop();



		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (maze[i][j] == '@')
				{
					qHuman.push({ i,j });
					human[i][j] = 1;
				}
				else if (maze[i][j] == '*')
				{
					qFire.push({ i,j }); 
					fire[i][j] = 1;
				}
			}
		}


		pair<int, int> cur;
		while (!qHuman.empty())
		{
			cur = qHuman.front(); qHuman.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
				if ((maze[ny][nx] != '#') && (human[ny][nx] == 0))
				{
					human[ny][nx] = human[cur.y][cur.x] + 1;
					qHuman.push({ ny, nx });
				}
			}
		}
		
		while (!qFire.empty())
		{
			cur = qFire.front(); qFire.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if ((maze[ny][nx] != '#') && (fire[ny][nx] == 0))
				{
					fire[ny][nx] = fire[cur.y][cur.x] + 1;
					qFire.push({ ny, nx });
				}
			}
		}


		int mn = INT_MAX;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if ((i == 0) || (i == h-1) || (j == 0) || (j == w-1))
				{
					if (human[i][j] == 0) continue;
					if (fire[i][j] == 0)
						fire[i][j] = INT_MAX;
					if (fire[i][j] > human[i][j])
						mn = min(human[i][j], mn);
				}
			}
		}


		if (mn != INT_MAX)
			cout << mn << endl;
		else 
			cout << "IMPOSSIBLE" << endl;


	}
}