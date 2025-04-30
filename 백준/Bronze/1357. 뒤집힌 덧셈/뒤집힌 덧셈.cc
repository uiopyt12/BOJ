#include <bits/stdc++.h>
using namespace std;

int main()
{
	string x, y;
	cin >> x >> y;
	string revX = x, revY = y;
	for (int i = x.length()-1; i >= 0; i--)
		revX[x.length() - 1 - i] = x[i];
	for (int i = y.length() - 1; i >= 0; i--)
		revY[y.length() - 1 - i] = y[i];

	int sum = stoi(revX) + stoi(revY);
	string revSum = to_string(sum);
	string orgSum = revSum;
	for (int i = revSum.length() - 1; i >= 0; i--)
	{
		orgSum[revSum.length() - 1 - i] = revSum[i];
	}
	cout << stoi(orgSum);
}