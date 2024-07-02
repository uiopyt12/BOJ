#include <bits/stdc++.h>

using namespace std;

int board[100][100][100];
int vis[100][100][100]; // init to Zer0
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, 1, -1 };

typedef struct c3 { // coordinate 3
	int z, y, x;
}c3;


int main()
{
	int m, n, h;
	cin >> m >> n >> h;
	c3 tempC;

	queue<c3> q;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];

				if (board[i][j][k] == 1)
				{
					tempC = { i, j, k };
					q.push(tempC);
					vis[i][j][k] = 1;
				}
				else if (board[i][j][k] == -1)
					vis[i][j][k] = -1;
			}
		}
	}





	while (!q.empty())
	{
		c3 cur = q.front(); q.pop();

		for (int i = 0; i < 6; i++)
		{
			if (  !(cur.x + dx[i] < 0 || cur.x + dx[i] >= m || cur.y + dy[i] < 0 || cur.y + dy[i] >= n || cur.z + dz[i] < 0 || cur.z + dz[i] >= h) && // 범위 내에 있고
				(vis[cur.z + dz[i]][cur.y + dy[i]][cur.x + dx[i]] == 0) && // 방문하지 않았고
				(board[cur.z + dz[i]][cur.y + dy[i]][cur.x + dx[i]] == 0) // 익지 않은 토마토
			)
			{
				q.push({ cur.z + dz[i], cur.y + dy[i],  cur.x + dx[i] });
				vis[cur.z + dz[i]][cur.y + dy[i]][cur.x + dx[i]] = vis[cur.z][cur.y][cur.x] + 1;
				board[cur.z + dz[i]][cur.y + dy[i]][cur.x + dx[i]] = 1; // 토마토 익음
			}
		}
	}

	int output = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				output = max(output, vis[i][j][k]);
				if (vis[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	cout << output-1;

}