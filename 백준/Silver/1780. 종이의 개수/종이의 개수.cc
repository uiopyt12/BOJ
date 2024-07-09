#include <bits/stdc++.h>
using namespace std;

int gpt[2187][2187]; // char gpt..
int negat, zero, posit;


void three(int row, int col, int n)
{
	int temp = gpt[row][col];
	bool onePage = true;
	for (int i = row; i < row+n; i++) // 종이가 모두 같은 숫자로 이루어졌는지 체크
	{
		if (onePage == false)
			break;
		for (int j = col; j < col+n; j++)
		{
			if (temp != gpt[i][j])
			{
				onePage = false;
				break;
			}
		}
	}

	if (onePage == true)
	{
		temp < 0 ? negat++ : (temp == 0 ? zero++ : posit++);
		return;
	}

	for (int i = row; i < row + n; i += n / 3)
	{
		for (int j = col; j < col + n; j += n / 3)
		{
			three(i, j, n / 3);
		}
	}

}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> gpt[i][j];
		}
	}
	

	three(0, 0, n);



	cout << negat << '\n' << zero  << '\n' << posit;
}