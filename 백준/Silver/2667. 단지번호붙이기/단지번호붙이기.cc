#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char isVisit[25][25];
bool house[25][25];
int n;
int numComplex; // 단지 수

int bfs(int r, int c);
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> isVisit[i][j];

	vector<int> area;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isVisit[i][j] == '1')
			{
				numComplex++;
				area.push_back(bfs(i, j));
			}
		}
	}

	sort(area.begin(), area.end());

	cout << numComplex << '\n';
	for (int i = 0; i < area.size(); i++)
		cout << area[i] << '\n';
}

int bfs(int r, int c)
{
	int area = 1;
	queue<pair<int, int>> q;
	q.push({ r,c });
	isVisit[r][c] = '2';
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir]; 
			if (!(isVisit[ny][nx] == '1')) continue;  
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			q.push({ ny, nx });
			isVisit[ny][nx] = '2'; // 중복 방문 방지
			area++;
		}
	}

	return area;
}