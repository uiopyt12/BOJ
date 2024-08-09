#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool isVisited[1005];

void bfs(int curVertex)
{
	isVisited[curVertex] = true;	
	queue<int> q;
	q.push(curVertex);
	while (!q.empty())
	{
		int cur = q.front(); 
		q.pop();
		for (auto nxt : adjList[cur]) // adjList[cur]이 1차원 벡터이므로 nxt는 int로 추론될것임
		{
			if (isVisited[nxt] == true) continue;
			isVisited[nxt] = true;
			q.push(nxt);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertex, edge;
	cin >> vertex >> edge;

	int start, end;
	for (int i = 0; i < edge; i++)
	{
		cin >> start >> end;
		adjList[start].push_back(end);	
		adjList[end].push_back(start);
	}
	
	int cmpnt=0;
	for (int i = 1; i <= vertex; i++)
	{
		if (isVisited[i] == true) continue;
		bfs(i);
		cmpnt++;
	}
	

	cout << cmpnt;
}