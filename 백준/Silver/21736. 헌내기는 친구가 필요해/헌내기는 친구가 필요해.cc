#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<bool>> isVisited(n, vector<bool>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
			{
				q.push({ i,j });
				isVisited[i][j] = true;
			}
		}
	}


	int canMeet = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] == 'X') continue;
			if (isVisited[ny][nx] == true) continue;
			if (board[ny][nx] == 'P')
			{
				canMeet++;
				board[ny][nx] = 'O';
			}
			isVisited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	
	if (canMeet == 0)
		cout << "TT";
	else
		cout << canMeet;
}