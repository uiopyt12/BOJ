#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

char board[100][100];
bool visit[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	int n;
	cin >> n;


	char temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			board[i][j] = temp;;
		}
	}



	int cArea =0; // color Area, blind Area
	queue<pair<int, int>> q;
	char cc = NULL; // cc means current color

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] != 0) continue;

			visit[i][j] = 1;
			cc = board[i][j];
			cArea++;
			q.push({ i , j });
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				visit[cur.x][cur.y] = 1;

				for (int i = 0; i < 4; i++)
				{
					if (!(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= n)  // not escaping map
						&& (visit[cur.x + dx[i]][cur.y + dy[i]] == 0) && // not visiting
						(board[cur.x + dx[i]][cur.y + dy[i]]) == cc) // can travel
					{
						q.push({ cur.x + dx[i], cur.y + dy[i] });
						visit[cur.x + dx[i]][cur.y + dy[i]] = 1; // marking In this loop, preventing pusing same coordinate twice
					} // if
				} // for
			} // while
		}
	}




	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++)
	{
		fill(visit[i], visit[i] + 100, 0);
	}
	
	int bArea = 0; //blind Area
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] != 0) continue;

			visit[i][j] = 1;
			cc = board[i][j];
			bArea++;
			q.push({ i , j });
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				visit[cur.x][cur.y] = 1;

				for (int i = 0; i < 4; i++)
				{
					if (!(cur.x + dx[i] < 0 || cur.x + dx[i] >= n || cur.y + dy[i] < 0 || cur.y + dy[i] >= n)  // not escaping map
						&& (visit[cur.x + dx[i]][cur.y + dy[i]] == 0) && // not visiting
						(board[cur.x + dx[i]][cur.y + dy[i]]) == cc) // can travel
					{
						q.push({ cur.x + dx[i], cur.y + dy[i] });
						visit[cur.x + dx[i]][cur.y + dy[i]] = 1; // marking In this loop, preventing pusing same coordinate twice
					} // if
				} // for
			} // while
		}
	}



	cout << cArea << ' ' << bArea << endl;
}