#include <bits/stdc++.h>
using namespace std;

// 2025, 3025, 9801

int main()
{
	int x;
	cin >> x;
	if (x < 2025)
		cout << 2025;
	else if (x < 3025)
		cout << 3025;
	else if (x < 9801)
		cout << 9801;
	else
		cout << -1;
}