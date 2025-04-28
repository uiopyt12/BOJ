#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t, a, b;
	cin >> t;
	for (int tk = 0; tk < t; tk++)
	{
		cin >> a >> b;
		int oa = a, ob = b;
		int r = a % b;
		while (r != 0)
		{
			a = b;
			b = r;
			r = a % b;
		}
		int gcd = b;
		cout << gcd * oa/gcd * ob/gcd << '\n';
	}
}