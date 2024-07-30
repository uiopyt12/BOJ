#include <bits/stdc++.h>
using namespace std;

map<string, int> pokeNumber; // 포켓몬 이름이 정렬됨
string pokeName[100001]; // 도감 번호가 정렬됨

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> pokeName[i];
		pokeNumber.insert({ pokeName[i], i });
	}

	string tmp;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (tmp.front() >= '0' && tmp.front() <= '9') // 도감 번호가 들어오면
		{
			cout << pokeName[(stoi(tmp))] << '\n'; 
		}

		else // 포켓몬 이름이 들어오면
		{
			map<string, int>::iterator it = pokeNumber.find(tmp);
			cout << it->second << '\n';
		}
	}
}