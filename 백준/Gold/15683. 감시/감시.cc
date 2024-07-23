#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;

int board[10][10]; // first는 cctv 및 벽 정보, second는 방향을 나타내도록 저장한 변수이다. 1-index로 저장됨 
int initBoard[10][10];
pair<int, int> cctvCoord[10];
int n, m; // 사무실이 n행 m열로 이루어짐을 나타내는 변수이다.
int k; // cctv의 개수를 저장하는 변수이다.
int curBlindSpot; // 사각지대의 개수를 저장하는 변수이다.
int minBlindSpot;
int num[8];

void cctv_ON(int r, int c, int dir)
{
	switch (dir)
	{
	case 0: // 오른쪽
		c++;
		while (board[r][c] != -1) // 6은 -1과 같게 처리함
		{
			if (board[r][c] == 0)
				board[r][c] = 8;
			c++; // x좌표 증가
		}
		break;

	case 1: // 아래
		r++;
		while (board[r][c] != -1) // 6은 -1과 같게 처리함
		{
			if (board[r][c] == 0)
				board[r][c] = 8;
			r++; // y좌표 증가
		}
		break;

	case 2: // 왼쪽
		c--;
		while (board[r][c] != -1) // 6은 -1과 같게 처리함
		{
			if (board[r][c] == 0)
				board[r][c] = 8;
			c--; // x좌표 감소
		}
		break;

	case 3: // 위
		r--;
		while (board[r][c] != -1) // 6은 -1과 같게 처리함
		{
			if (board[r][c] == 0)
				board[r][c] = 8;
			r--; // y좌표 감소
		}
		break;

	}


}


void permutation(int level)
{
	if (level == k)
	{
		copy(&initBoard[0][0], &initBoard[9][9], &board[0][0]);
		for (int i = 0; i < level; i++)
		{
			switch (board[cctvCoord[i].y][cctvCoord[i].x]) // 몇 번 CCTV인지 확인하는 코드
			{
			case 1:
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, num[i]);
				break;

			case 2: // 일자 모양 CCTV
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, num[i]); 
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+2)%4);
				break;

			case 3: // 직각 모양 CCTV
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, num[i]);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+1)%4);
				break;
			case 4:
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, num[i]);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+2)%4);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+3)%4);
				break;
			case 5:
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, num[i]);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+1)%4);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+2)%4);
				cctv_ON(cctvCoord[i].y, cctvCoord[i].x, (num[i]+3)%4);
				break;
			}
			
		}

		curBlindSpot = 0;
		for (int i = 1; i <= 8; i++) // 검사
		{
			for (int j = 1; j <= 8; j++)
			{
				if (board[i][j] == 0)
					curBlindSpot++;
			}
		}

		minBlindSpot = min(minBlindSpot, curBlindSpot);

		return;
	}


	for (int i = 0; i < 4; i++)
	{
		num[level] = i;
		permutation(level + 1);
	}


}

int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			board[i][j] = -1; // 사무실 바깥을 -1로 처리

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) // cctv인 경우
			{
				cctvCoord[k].y = i;
				cctvCoord[k].x = j;
				k++; // cctv의 개수 증가
			}
			else if (board[i][j] == 0) // 빈 공간인 경우
			{
				minBlindSpot++;
			}

			else if (board[i][j] == 6) // 벽인 경우
			{
				board[i][j] = -1;
			}
		}
	}

	copy(&board[0][0], &board[9][9], &initBoard[0][0]);

	permutation(0);

	cout << minBlindSpot << '\n';
}