#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1001];
bool isVisited[1001];

void dfs(int cur)
{
	isVisited[cur] = true;
	cout << cur << ' ';
	for (const auto& iter : adjList[cur])
	{
		if (isVisited[iter] == true) continue;
		dfs(iter);
	}
}

int main()
{
	int vertex, edge, startVertex;
	cin >> vertex >> edge >> startVertex;
	for (int i = 0; i < edge; i++)
	{
		int start, end;
		cin >> start >> end;
		adjList[start].push_back(end);
		adjList[end].push_back(start);
	}

	for (auto& eachList : adjList)
		sort(eachList.begin(), eachList.end());

	dfs(startVertex);

	for (auto& it : isVisited)
		it = false;
	cout << '\n' << startVertex << ' ';

	queue<int> q;
	q.push(startVertex);
	isVisited[startVertex] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (const auto& iter : adjList[cur])
		{
			if (isVisited[iter] == true) continue;
			q.push(iter);
			isVisited[iter] = true;
			cout << iter << ' ';
		}
	}
}