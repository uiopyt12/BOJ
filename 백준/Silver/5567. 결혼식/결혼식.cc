#include <bits/stdc++.h>
using namespace std;

bool isAdjacency[501][501];
bool isVisited[501];

int main()
{
	int vertex, edge;
	cin >> vertex >> edge;
	vector<int> friendV;
	friendV.push_back(1);
	for (int i = 0; i < edge; i++)
	{
		int start, end;
		cin >> start >> end;
		isAdjacency[start][end] = true;
		isAdjacency[end][start] = true;

		if (start == 1) friendV.push_back(end);
		else if (end == 1) friendV.push_back(start);
	}

	int invited = 0;
	for (const auto& directFriend : friendV)
	{
		for (int i = 2; i <= vertex; i++) // 간접적 친구는 친구의 친구를 의미
		{// i가 1일 때에는 제외
			if (isAdjacency[directFriend][i] == false) continue;
			if (isVisited[i] == true) continue;
			isVisited[i] = true;
			invited++;
		}
	}

	cout << invited;

}