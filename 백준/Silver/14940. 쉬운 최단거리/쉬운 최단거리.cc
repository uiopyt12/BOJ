#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
bool isVisited[1000][1000];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int n, m;

int main()
{
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				q.push({ i,j }); 
				board[i][j] = 0; 
				isVisited[i][j] = true;
			}
		}
	}
	


	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 맵에서 벗어나면 방문하지 않음
			if (isVisited[ny][nx] == true) continue; // 방문했었으면 방문하지 않음
			if (board[ny][nx] == 0) continue; // 0이면 방문하지 않음 (원래 갈 수 없는 땅)
			q.push({ ny, nx });
			isVisited[ny][nx] = true;
			board[ny][nx] = board[cur.first][cur.second] + 1;
		}
	}

	


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && isVisited[i][j] == false) // 원래 갈 수 있는 땅이지만 도달할 수 없는 경우
			{
				board[i][j] = -1;
			}
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}


}