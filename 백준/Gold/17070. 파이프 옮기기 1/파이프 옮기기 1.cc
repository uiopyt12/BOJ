#include <bits/stdc++.h>
using namespace std;

int houseSize;
int house[20][20]; // 1-index 사용
int way = 0;

void moving(int r, int c, int state)
{
	if (state == 0) { // 가로
		if (r <= 0 || r > houseSize || c <= 0 || c >= houseSize) return;
		if (house[r][c] == 1 || house[r][c + 1] == 1) return;
		if (r == houseSize && c == houseSize - 1) {
			way++;
			return;
		}
		moving(r, c + 1, 0);
		moving(r, c + 1, 2);
	}
	else if (state == 1) { // 세로
		if (r <= 0 || r >= houseSize || c <= 0 || c > houseSize) return;
		if (house[r][c] == 1 || house[r + 1][c] == 1) return;
		if (r == houseSize - 1 && c == houseSize) {
			way++;
			return;
		}
		moving(r + 1, c, 1);
		moving(r + 1, c, 2);
	}
	else if (state == 2) { // 대각선
		if (r <= 0 || r >= houseSize || c <= 0 || c >= houseSize) return;
		if (house[r][c] == 1 || house[r][c + 1] == 1 || house[r + 1][c] == 1 || house[r + 1][c + 1] == 1) return;
		if (r == houseSize - 1 && c == houseSize - 1) {
			way++;
			return;
		}
		moving(r + 1, c + 1, 0);
		moving(r + 1, c + 1, 1);
		moving(r + 1, c + 1, 2);
	}
}


int main()
{
	cin >> houseSize;

	for (int i = 1; i <= houseSize; i++) // 입력도 1-index로 받아야 함
		for (int j = 1; j <= houseSize; j++)
			cin >> house[i][j];

	int r = 1, c = 1, state = 0; // r과 c는 파이프가 차지하고 있는 칸 중 가장 왼쪽 위에 가까운 칸
	//state는 파이프의 상태를 나타냄, 0은 가로, 1은 세로, 2는 대각선

	moving(r, c, state);

	cout << way;
}