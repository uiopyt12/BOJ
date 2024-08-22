#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool CoordSorting(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) // y 좌표가 같다면
		return p1.second < p2.second; // x 좌표를 오름차순으로

	return p1.first < p2.first;
		
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int size = 2;
	int exp = 0;
	int ans = 0;
	pair<int, int> sharkCoord;

	while (true){
		queue<pair<int, int>> q, tmpQ;
		bool isVisited[20][20] = { false };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 9)
					sharkCoord = { i,j };

		tmpQ.push(sharkCoord);
		isVisited[sharkCoord.first][sharkCoord.second] = true;

		vector <pair<int, int>> canEat;
		bool keepGoing = true;
		int sec = 0;
		while (keepGoing == true)
		{
			if (tmpQ.empty())
				keepGoing = false;
			while (!tmpQ.empty())
			{
				q.push(tmpQ.front());
				tmpQ.pop();
			}
			sec++;
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if (isVisited[ny][nx] == true) continue;
					if (board[ny][nx] > size) // 이동하려는 칸의 물고기가 아기 상어의 크기보다 큰 경우, 지나갈 수 없다.
					{
						isVisited[ny][nx] = true;
						continue;
					}
					else if ((board[ny][nx] == size || board[ny][nx] == 0))
					{
						isVisited[ny][nx] = true;
						tmpQ.push({ ny,nx });
					}
					else if (board[ny][nx] != 0 && board[ny][nx] < size) // 이동하려는 칸의 물고기를 먹을 수 있는 경우
					{
						isVisited[ny][nx] = true;
						tmpQ.push({ ny,nx });
						canEat.push_back({ ny,nx });
						keepGoing = false;
					}
				}
			}
		}
		stable_sort(canEat.begin(), canEat.end(), CoordSorting); // 위쪽, 그리고 왼쪽 물고기를 먹을 수 있게 정렬

		if (canEat.empty() == true) {
			cout << ans;
			break;
		}
		else {
			ans += sec;
			sec = 0;
			exp++;
			if (exp == size)
			{
				size++; exp = 0;
			}
			board[sharkCoord.first][sharkCoord.second] = 0;
			board[canEat[0].first][canEat[0].second] = 9;
			swap(canEat[0], sharkCoord);
		}
	}

}