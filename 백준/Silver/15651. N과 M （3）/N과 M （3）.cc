#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];
void permutation(int k)
{
	if (k == m)
	{
		for (int i = 0; i < k; i++)
			cout << arr[i]+1 << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		arr[k] = i;
		permutation(k + 1);
	}
	

}


int main()
{
	cin >> n >> m;
	permutation(0);
}