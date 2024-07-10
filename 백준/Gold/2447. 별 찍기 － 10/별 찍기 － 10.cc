#include <bits/stdc++.h>
using namespace std;

char star[2187][2187];
void makeSpace(int r, int c, int n)
{
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			star[i][j] = ' ';
		}
	}

}
void makeStar(int r, int c, int n)
{
	if (n == 3)
	{
		for (int i = r; i < r+3; i++)
		{
			for (int j = c; j < c+3; j++)
			{
				if (i == r + 1 && j == c+1)
					star[i][j] = ' ';
				else
					star[i][j] = '*';
			}
		}
	}

	else
	{
		int delta = n / 3;
		for (int i = r; i < r + n; i+=delta)
		{
			for (int j = c; j < c + n; j+=delta)
			{
				if (i == r + delta && j == c + delta)
				{
					makeSpace(i, j, delta);
				}
				else
					makeStar(i, j, n/3);
					
			}
		}


	}


}

int main()
{
	int n;
	cin >> n;

	makeStar(0, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << star[i][j];
		}
		cout << '\n';
	}


}