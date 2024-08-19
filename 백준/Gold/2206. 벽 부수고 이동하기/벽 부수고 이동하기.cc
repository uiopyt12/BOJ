#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
int distFromStart[1000][1000];
int distFromEnd[1000][1000];
bool isVisited[1000][1000];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int n, m;
int minDist = 1048576;

int main()
{
	cin >> n >> m;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = tmp[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({ n - 1, m - 1 });
	isVisited[n - 1][m - 1] = true;
	distFromEnd[n - 1][m - 1] = 1;
	while (!q.empty()) // 도착 지점에서의 BFS
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (isVisited[ny][nx] == true) continue;
			if (board[ny][nx] == 1) continue;
			q.push({ ny, nx });
			isVisited[ny][nx] = true;
			distFromEnd[ny][nx] = distFromEnd[cur.first][cur.second] + 1;
		}
	}


	q.push({ 0,0 });
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			isVisited[i][j] = 0;
	isVisited[0][0] = true;
	distFromStart[0][0] = 1;
	while (!q.empty()) // 시작 지점에서의 BFS
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (isVisited[ny][nx] == true) continue;
			if (board[ny][nx] == 1)
			{
				for (int dir2 = 0; dir2 < 4; dir2++)
				{
					int ny2 = ny + dy[dir2];
					int nx2 = nx + dx[dir2];
					if (ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= m) continue;
					if (cur.first == ny2 && cur.second == nx2) continue; // 벽을 뚫고 다시 원래 자리로 돌아온 경우
					if (distFromEnd[ny2][nx2] == 0) continue; // 벽이 아니고 도착 지점으로부터 벽을 뚫지 않고 도달할 수 있으면
					minDist = min(minDist, distFromStart[cur.first][cur.second] + distFromEnd[ny2][nx2] + 1);
				}
			}
			else
			{
				q.push({ ny, nx });
				isVisited[ny][nx] = true;
				distFromStart[ny][nx] = distFromStart[cur.first][cur.second] + 1;
				if (distFromEnd[ny][nx] != 0)
					minDist = min(minDist, distFromStart[ny][nx] + distFromEnd[ny][nx] - 1);
			}
		}
	}


	if (distFromStart[n - 1][m - 1] != 0)
		minDist = min(minDist, distFromStart[n - 1][m - 1]);

	if (minDist == 1048576)
		cout << -1;
	else
		cout << minDist;
}