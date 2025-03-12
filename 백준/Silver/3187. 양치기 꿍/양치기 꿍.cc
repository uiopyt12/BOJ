#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	int r, c;
	cin >> r >> c;
	int wolf = 0, sheep = 0;
	vector<vector<char>> map(r, vector<char>(c, '.'));
	vector<vector<bool>> isVisited(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'k')
				sheep++;
			else if (map[i][j] == 'v')
				wolf++;
		}
	}

	queue<pair<int, int>> q;
	int localSheep = 0, localWolf = 0; // 한 울타리 내부의 양과 늑대의 수
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'k')
			{
				localSheep = 0, localWolf = 0;
				q.push({ i,j });
				isVisited[i][j] = true;
				localSheep++;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];

						if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
						if (isVisited[ny][nx] == true) continue;
						if (map[ny][nx] == '#') continue;
						if (map[ny][nx] == 'v') localWolf++;
						if (map[ny][nx] == 'k') localSheep++;
						q.push({ ny,nx });
						isVisited[ny][nx] = true;
					}
				}
				if (localSheep > localWolf) wolf -= localWolf;
				else sheep -= localSheep;
			}
		}
	}
	cout << sheep << ' ' << wolf;


}