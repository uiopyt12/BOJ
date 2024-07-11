#include <bits/stdc++.h>
using namespace std;

char gpt[64][64];


bool check(int r, int c, int n) // 하나의 수로만 이루어져 있으면 true, 아니면 false 반환
{
	int temp = gpt[r][c];
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (temp != gpt[i][j])
				return false;
		}
	}

	return true;
}


void quadTree(int row, int col, int n)
{
	if (n == 1)
		cout << gpt[row][col];

	else
	{
		if (check(row, col, n) == true)
			cout << gpt[row][col];
		else
		{
			int half = n / 2; // n이 1이 아니면 항상 2의 거듭제곱이므로 n/2의 결과가 형변환되지 않아도 정수임

			cout << "(";			
			for (int i = row; i < row + n; i+=half)
			{
				for (int j = col; j < col + n; j+=half)
				{
					quadTree(i, j, half);
				}
			}
			cout << ")";

		}
	}
	

}


int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> gpt[i][j];

	quadTree(0, 0, N);
}