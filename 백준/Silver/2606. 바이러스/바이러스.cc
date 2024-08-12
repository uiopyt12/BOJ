#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[101];
bool isVisited[101];

int main()
{
	int vertex, edge;
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) // 간선 입력받음
	{
		int start, end;
		cin >> start >> end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}


	int virus = 0;
	stack<int> stak;
	stak.push(1);
	while (!stak.empty())
	{
		int cur = stak.top();
		stak.pop();
		if (isVisited[cur] == true) continue;
		isVisited[cur] = true;
		virus++;
		for (const auto& nxt : adjList[cur])
		{
			if (isVisited[nxt] == true) continue;
			stak.push(nxt);
		}
	}
	cout << virus-1;
}