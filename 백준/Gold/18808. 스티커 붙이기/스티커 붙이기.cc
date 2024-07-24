#include <bits/stdc++.h>
using namespace std;

int notebook[40][40];
bool sticker[10][10];
int n, m, k;

//스티커를 붙일 수 있으면 붙이고 참을 반환, 그렇지 않으면 스티커를 붙이지 않고 거짓을 반환하는 함수
bool attatchSticker(int startR, int startC, int r, int c) // notebook[startR][startC]에 r * c 크기의 스티커를 붙이려는 시도를 하는 함수
{
	if (startR + r-1 >= n || startC + c-1 >= m) return false; // 범위 바깥 검사

	// 스티커를 붙이는 도중에 false를 반환할 수 있음, 스티커를 붙이기 전 notebook 상황을 기억했다가 다시 돌려놓아야 함
	int tempSticker[10][10] = { 0 };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tempSticker[i][j] += sticker[i][j];
			tempSticker[i][j] += notebook[startR+i][startC+j];
			if (tempSticker[i][j] > 1) return false; // 스티커가 붙어있는 지 검사
		}
	}

	for (int i = 0; i < r; i++)
		copy(&tempSticker[i][0], &tempSticker[i][c], &notebook[startR+i][startC]);

	return true;
}

// 회전하는 것은 인덱스의 접근 방식만 바꿔서 구현 가능
void rotate(int r, int c) // sticker에 저장된 r * c 크기의 스티커를 시계 방향으로 90도 회전시키는 함수
{
	bool temp[10][10];
	copy(&sticker[0][0], &sticker[r][c], &temp[0][0]);
	fill(&sticker[0][0], &sticker[r][c], 0);
	for (int i = 0; i < c; i++) // i < c
	{
		for (int j = 0; j < r; j++) // j < r
		{
			sticker[i][j] = temp[r-1-j][i];
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;

		fill(&sticker[0][0], &sticker[0][0]+100, 0);
		for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			cin >> sticker[y][x];
		
		for (int rotated = 0; rotated < 4; rotated++)
		{
			if (rotated != 0)
			{
				rotate(r, c);
				swap(r, c);
			}

			bool flag = false;
			for (int notebookR = 0; notebookR < n && flag == false; notebookR++)
			{
				for (int notebookC = 0; notebookC < m && flag == false; notebookC++)
				{
					flag = attatchSticker(notebookR, notebookC, r, c);
				}
			}
			if (flag == true) break;
		}
	}

	cout << accumulate(&notebook[0][0], &notebook[n][m], 0);
}