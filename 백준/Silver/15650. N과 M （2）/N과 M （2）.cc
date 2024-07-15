#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];
void permutation(int k)
{
	if (k == m)
	{
		for (int i = 0; i < k-1; i++)
		{
			if (arr[i] > arr[i + 1])
				return;
		}
		for (int i = 0; i < k; i++)
			cout << arr[i]+1 << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (isUsed[i] == true)
			continue;

		arr[k] = i;
		isUsed[i] = true;
		permutation(k + 1);
		isUsed[i] = false;
	}
	

}


int main()
{
	cin >> n >> m;
	permutation(0);
}