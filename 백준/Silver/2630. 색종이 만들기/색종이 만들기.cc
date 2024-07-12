#include <bits/stdc++.h>
using namespace std;

int gpt[128][128]; // char gpt..
int whiteBlue[2]; // white is zero

bool check(int n, int r, int c)
{
	int temp = gpt[r][c];
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (temp != gpt[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void quadTree(int n, int r, int c)
{
	if (check(n, r, c) == true)
		whiteBlue[ gpt[r][c] ]++;
	else
	{
		int half = n / 2;
		for (int i = r; i < r + n; i+=half)
		{
			for (int j = c; j < c + n; j+=half)
			{
				quadTree(half, i, j);
			}
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


	quadTree(n, 0, 0);


	cout << whiteBlue[0] << endl << whiteBlue[1];
}