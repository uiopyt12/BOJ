#include <bits/stdc++.h>
using namespace std;

bool cmpReverse(int a, int b) 
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end(), cmpReverse);
	sort(b.begin(), b.end());

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];

	cout << sum;
}