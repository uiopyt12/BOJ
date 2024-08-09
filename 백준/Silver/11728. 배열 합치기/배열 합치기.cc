#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSort(vector<int>& a, vector<int>& b)
{
	vector<int> result;
	vector<int>::iterator iter;
	int aIdx = 0, bIdx = 0;
	while (aIdx < a.size() && bIdx < b.size())
	{
		if (a[aIdx] <= b[bIdx])
		{
			result.push_back(a[aIdx]);
			aIdx++;
		}
		else
		{
			result.push_back(b[bIdx]);
			bIdx++;
		}
	}

	if (aIdx == a.size())
	{
		while (bIdx < b.size())
		{
			result.push_back(b[bIdx]);
			bIdx++;
		}
	}
	else if (bIdx == b.size())
	{
		while (aIdx < a.size())
		{
			result.push_back(a[aIdx]);
			aIdx++;
		}

	}
	


	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	vector<int> res = mergeSort(a, b);
	for (auto iter : res)
		cout << iter << ' ';
}