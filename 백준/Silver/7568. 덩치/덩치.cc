#include <bits/stdc++.h>
using namespace std;

typedef struct info
{
	int num;
	int weight;
	int height;
	int rank;
};

bool compareBody(const info& a, const info& b)
{
	return (a.weight > b.weight) && (a.height > b.height);
}

bool compareNum(const info& a, const info& b) // 오름차순 정렬
{
	return (a.num < b.num);
}

int main()
{
	int n;
	cin >> n;

	vector<info> v(n, {0, 0, 0, 0});

	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v[i] = { i,x,y };
	}
	sort(v.begin(), v.end(), compareBody);
	
	v[0].rank = 0+1; // 큰사람 0명 +1이 등수
	for (int i = 1; i < n; i++)
	{
		int r = 0;
		for (int j = 0; j < n; j++)
		{
			if (compareBody(v[j], v[i]) == true) // 덩치가 큰 사람의 수
				r++;
		}
			v[i].rank = r+1;
	}

	sort(v.begin(), v.end(), compareNum);
	for (auto it : v)
	{
		cout << it.rank << ' ';
	}

}