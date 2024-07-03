#include <bits/stdc++.h>
using namespace std;


long long power(long long a, long long b, long long c)
{
	if (b == 1) return a % c;
	else if (b % 2 == 0)
	{
		long long temp = power(a, b/2, c);
		return temp * temp % c;	
	}
	else if (b % 2 == 1)
	{
		return a * power(a, b - 1, c) % c;
	}
}


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << power(a, b, c);
}