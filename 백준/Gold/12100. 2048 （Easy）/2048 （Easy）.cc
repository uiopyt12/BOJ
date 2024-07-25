#include <bits/stdc++.h>
using namespace std;

int n;
int maxBlock;

void tiltBoard_right(int board[20][20])  // O(n)으로 보드를 기울이는 함수
{
	// 보드 기울이기
	for (int i = 0; i < n; i++) 
	{
		int zeroCnt = 0;
		for (int j = n-1; j >= 0; j--) 
		{
			if (board[i][j] == 0)
				zeroCnt++;
			else
				swap(board[i][j], board[i][j+zeroCnt]);
		}

		for (int j = n - 1; j >= 1; j--) // n-1 to 1
		{
			if (board[i][j] == board[i][j-1])
			{
				board[i][j] = board[i][j] << 1;
				board[i][j - 1] = 0;
			}
		}

		zeroCnt = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (board[i][j] == 0)
				zeroCnt++;
			else
				swap(board[i][j], board[i][j + zeroCnt]);
		}
	}
}
void tiltBoard_left(int board[20][20])  // O(n)으로 보드를 기울이는 함수
{
	for (int i = 0; i < n; i++)
	{
		int zeroCnt = 0;
		for (int j = 0; j < n; j++) 
		{
			if (board[i][j] == 0)
				zeroCnt++;
			else
				swap(board[i][j], board[i][j - zeroCnt]);
		}

		for (int j = 0; j < n-1; j++) // 0 to n-2
		{
			if (board[i][j] == board[i][j + 1])
			{
				board[i][j] = board[i][j] << 1;
				board[i][j + 1] = 0;
			}
		}

		zeroCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				zeroCnt++;
			else
				swap(board[i][j], board[i][j - zeroCnt]);
		}

	}
}
void tiltBoard_up(int board[20][20])  // O(n)으로 보드를 기울이는 함수
{
	for (int i = 0; i < n; i++)
	{
		int zeroCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == 0)
				zeroCnt++;
			else
				swap(board[j][i], board[j-zeroCnt][i]);
		}

		for (int j = 0; j < n - 1; j++) // 0 to n-2
		{
			if (board[j][i] == board[j+1][i])
			{
				board[j][i] = board[j][i] << 1;
				board[j+1][i] = 0;
			}
		}

		zeroCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == 0)
				zeroCnt++;
			else
				swap(board[j][i], board[j - zeroCnt][i]);
		}

	}



}
void tiltBoard_down(int board[20][20])  // O(n)으로 보드를 기울이는 함수
{
	for (int i = 0; i < n; i++)
	{
		int zeroCnt = 0;
		for (int j = n-1; j >= 0; j--)
		{
			if (board[j][i] == 0)
				zeroCnt++;
			else
				swap(board[j][i], board[j + zeroCnt][i]);
		}

		for (int j = n-1; j >=1; j--) // n-1 to 1
		{
			if (board[j][i] == board[j - 1][i])
			{
				board[j][i] = board[j][i] << 1;
				board[j - 1][i] = 0;
			}
		}

		zeroCnt = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (board[j][i] == 0)
				zeroCnt++;
			else
				swap(board[j][i], board[j + zeroCnt][i]);
		}

	}
}

void backtracking(int cur, int paramBoard[20][20])
{
	if (cur == 5)
	{
		int curMax = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			curMax = max(curMax, paramBoard[i][j]);

		maxBlock = max(maxBlock, curMax);
		return;
	}

	int curBoard[20][20] = { 0 };
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		curBoard[i][j] = paramBoard[i][j];

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					paramBoard[i][j] = curBoard[i][j];
			tiltBoard_right(paramBoard);
			backtracking(cur+1, paramBoard);
			break;

		case 1:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					paramBoard[i][j] = curBoard[i][j];
			tiltBoard_left(paramBoard);
			backtracking(cur+1, paramBoard);
			break;

		case 2:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					paramBoard[i][j] = curBoard[i][j];
			tiltBoard_up(paramBoard);
			backtracking(cur+1, paramBoard);
			break;

		case 3:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					paramBoard[i][j] = curBoard[i][j];
			tiltBoard_down(paramBoard);
			backtracking(cur+1, paramBoard);
			break;

		}
	}

}

int main()
{
	int board[20][20] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	backtracking(0, board);
	
	cout << maxBlock;

	return 0;
}