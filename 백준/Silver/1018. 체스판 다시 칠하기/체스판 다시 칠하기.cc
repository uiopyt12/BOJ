#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board(50, vector<char>(50));

int getRepaintFromBlackboard(int i, int j) // 왼쪽 위가 검은 색인 체스판을 Blackboard
{
	int repaint = 0;
	for (int dy = 0; dy < 8; dy++)
	{
		for (int dx = 0; dx < 8; dx++)
		{
			int cur = dy + dx;
			if (cur % 2 == 0 && board[i + dy][j+ dx] == 'W')
				repaint++;
			else if (cur % 2 == 1 && board[i + dy][j + dx] == 'B')
				repaint++;
		}
	}

	return repaint;
}

int getRepaintFromWhiteboard(int i, int j)
{
	int repaint = 0;
	for (int dy = 0; dy < 8; dy++)
	{
		for (int dx = 0; dx < 8; dx++)
		{
			int cur = dy + dx;
			if (cur % 2 == 0 && board[i + dy][j + dx] == 'B')
				repaint++;
			else if (cur % 2 == 1 && board[i + dy][j + dx] == 'W')
				repaint++;
		}
	}

	return repaint;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int minRepaint = 100;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];


	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			minRepaint = min(getRepaintFromBlackboard(i, j), minRepaint);
			minRepaint = min(getRepaintFromWhiteboard(i, j), minRepaint);
		}
	}


	cout << minRepaint;
}