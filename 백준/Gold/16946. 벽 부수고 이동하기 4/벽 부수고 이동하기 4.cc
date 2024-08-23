#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<int>> manipulatedBoard(n, vector<int>(m, 0)); 
	// 벽을 -1로, 벽이 없는 곳을 빈칸의 넓이로 저장하는 배열
	vector<vector<pair<int,int>>> visitInfo(n, vector<pair<int, int>>(m, {0, 0})); 
	// first는 방문 횟수, second는 식별 번호로 같은 영역에 대해서만 같은 식별 번호를 가지게 된다.
	char in;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> in;
			if (in == '1')
			{
				board[i][j] = 1;
				manipulatedBoard[i][j] = -1;
			}
		}
	}


	queue<pair<int, int>> q;
	pair<int, int> last; 
	// 마지막에 pop된, 즉 0의 영역의 최대 크기를 구하기 위한 변수
	int area;
	int id = 1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			id++;
			if (manipulatedBoard[i][j] == 0)
			{
				area = 1;
				q.push({ i,j });
				visitInfo[i][j].first = 1;
				visitInfo[i][j].second = id;
				while (!q.empty()) // 0인 영역의 넓이를 구하고 ID를 설정하기 위한 BFS
				{
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						if (visitInfo[ny][nx].first == 1) continue;
						if (manipulatedBoard[ny][nx] == -1) continue;
						q.push({ ny,nx });
						visitInfo[ny][nx].first = 1;
						visitInfo[ny][nx].second = visitInfo[i][j].second;
						area++;
						last = { ny, nx };
					}
				}

				if (area == 1)
					manipulatedBoard[i][j] = 1;
				else
					q.push(last);
				visitInfo[last.first][last.second].first = 2;
				while (!q.empty()) // 위 BFS에서 구한 0인 영역의 넓이를 표시하기 위한 BFS, 재전파
				{
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						if (visitInfo[ny][nx].first != 1) continue; // 방문 횟수가 0과 2면 통과
						if (manipulatedBoard[ny][nx] == -1) continue;
						q.push({ ny,nx });
						visitInfo[ny][nx].first = 2;
						visitInfo[ny][nx].second = id;
						manipulatedBoard[ny][nx] = area;
					}
				}
			}
		}
	}


	int tmp; // board[i][j] 위치의 벽을 부쉈을 때, 근처의 이동할 수 있는 칸의 개수를 누적해서 더해줄 변수, 초기값이 1인 것은 해당 칸도 이동할 수 있기 때문
	vector<int> isOnePiece(4);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp = 1;
			if (board[i][j] == 1)
			{
				pair<int, int> cur = { i,j };
				
				isOnePiece.clear();
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (manipulatedBoard[ny][nx] == -1) continue;
					int id = visitInfo[ny][nx].second;
					if (isOnePiece.end() != find(isOnePiece.begin(), isOnePiece.end(), id)) continue; // id가 존재하면
					isOnePiece.push_back(id);
					tmp += manipulatedBoard[ny][nx];
				}
				board[i][j] = tmp % 10;
			}
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", board[i][j]);
		}
		cout << '\n';
	}
}
