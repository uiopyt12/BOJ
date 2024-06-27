#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int board[50][50];
bool visit[50][50];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main()
{
	int testCase, width, height, k;
	int worm;
	cin >> testCase;
	
	for (int i = 0; i < testCase; i++)
	{
		fill(&board[0][0], &board[0][0] + 50 * 50, 0);
		fill(&visit[0][0], &visit[0][0] + 50 * 50, 0);
		cin >> width >> height >> k;

		
		
		int ix, iy;
		worm = 0;
		queue<pair<int, int>> q;

		for (int j = 0; j < k; j++)
		{
			cin >> ix >> iy;
			board[ix][iy] = 1;
		}

		
		for (int w = 0; w < width; w++)
		{
			for (int h = 0; h < height; h++)
			{
				if (visit[w][h] == 1 || board[w][h] == 0)	continue;

				visit[w][h] = 1;
				q.push({ w, h });
				worm++;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					visit[cur.x][cur.y] = 1;

					for (int i = 0; i < 4; i++)
					{
						if (!(cur.x + dx[i] < 0 || cur.x + dx[i] >= width || cur.y + dy[i] < 0 || cur.y + dy[i] >= height)  // not escaping map
							&& (visit[cur.x + dx[i]][cur.y + dy[i]] == 0) && // not visiting
							(board[cur.x + dx[i]][cur.y + dy[i]]) == 1) // can travel
						{
							q.push({ cur.x + dx[i], cur.y + dy[i] });
							visit[cur.x + dx[i]][cur.y + dy[i]] = 1; // marking In this loop, preventing pusing same coordinate twice
						} // if
					} // for
				} // while
			}
		}


		cout << worm << endl;

	}
}