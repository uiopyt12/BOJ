#include <bits/stdc++.h>
using namespace std;

int a[100];

int main()
{
	int n;
	cin >> n;

	int score = 0;
	int pre = 0;
	int sum;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum = 0;
		for (int j = i-1; j >= 0; j--)
		{
			sum += a[j];
		}
		score += sum * a[i];
	}

	cout << score;

}