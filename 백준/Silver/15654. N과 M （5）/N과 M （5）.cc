#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isUsed[10];

void permutation(int k)
{
	if (m == k)
	{
		for (int i=0; i<m; i++)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (isUsed[i] == true)
			continue;
		isUsed[i] = true;
		arr[k] = i;
		permutation(k + 1);
		isUsed[i] = false;
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + n + 1); // except 0

	permutation(0);
}