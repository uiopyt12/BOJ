#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int tmp;
	priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}

	long long ans = 0;
	while (pq.size() >= 2)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}

	cout << ans;
}