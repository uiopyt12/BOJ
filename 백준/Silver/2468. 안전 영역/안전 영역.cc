#include <bits/stdc++.h>
using namespace std;

int board[100][100];
bool isVisited[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1 ,0 };
int n;
int maxSafetyArea = 1;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}


	
	for (int height = 1; height <= 100; height++)
	{
		for (int i = 0; i < n; i++) // 배열 초기화
		for (int j = 0; j < n; j++)
			isVisited[i][j] = false;

		queue<pair<int, int>> q;
		int curSafetyArea = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{	
				if (board[i][j] <= height) // 침수처리
				{
					board[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) // BFS를 통한 안전영역 구하기
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0) continue; // 침수된 영역은 패스
				if (isVisited[i][j] == false)
				{
					q.push({ i,j });
					isVisited[i][j] = true;
					while (!q.empty())
					{
						pair<int, int> cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int ny = cur.first + dy[dir];
							int nx = cur.second + dx[dir];
							if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue; // 범위 밖으로 벗어나지 않으면서
							if (board[ny][nx] == 0) continue; // 침수되지 않았고
							if (isVisited[ny][nx] == 1) continue; // 방문한 적이 없으면
							q.push({ ny, nx });
							isVisited[ny][nx] = true;
						}
					}
					curSafetyArea++;
				}
			}
		}
		
		if (curSafetyArea == 0) break;

		maxSafetyArea = max(maxSafetyArea, curSafetyArea);
	}




	cout << maxSafetyArea;

}