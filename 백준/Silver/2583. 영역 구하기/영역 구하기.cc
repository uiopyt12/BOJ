#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool isVisit[101][101];
//int paper[101][101];
int m, n;
int numArea; 

int bfs(int r, int c);
int main()
{
	int k;
	cin >> m >> n >> k;

	int x1, y1, x2, y2;
	while (k--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		y1 = m - y1; // 왼쪽 위에서 시작하는 좌표로 맞춤
		y2 = m - y2;

		for (int i = y2; i < y1; i++) // 좌표 변환으로 인해 y2가 더 작음
		for (int j = x1; j < x2; j++)
			isVisit[i][j] = true;
	}

	
	vector<int> area;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isVisit[i][j] == false)
			{
				numArea++;
				area.push_back(bfs(i, j));
			}
		}
	}


	sort(area.begin(), area.end());

	cout << numArea << '\n';
	for (int i = 0; i < area.size(); i++)
		cout << area[i] << ' ';



}

int bfs(int r, int c)
{
	int area = 1;
	queue<pair<int, int>> q;
	q.push({ r,c });
	isVisit[r][c] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir]; 
			if (isVisit[ny][nx] == true) continue; 
			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

			q.push({ ny, nx });
			isVisit[ny][nx] = true; // 중복 방문 방지
			area++;
		}
	}

	return area;
}