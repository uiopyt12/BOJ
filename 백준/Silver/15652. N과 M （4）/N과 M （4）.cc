#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];
void permutation(int k, int start)
{
	if (k == m)
	{
		for (int i = 0; i < k; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = start; i <= n; i++)
	{
		a[k] = i;
		permutation(k + 1, i);
	}
	

}


int main()
{
	cin >> n >> m;
	permutation(0, 1);
}