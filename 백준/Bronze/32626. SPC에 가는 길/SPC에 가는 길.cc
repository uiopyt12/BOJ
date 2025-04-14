#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second 

int main()
{
	pair<int, int> s, e, p;
	cin >> s.x >> s.y >> e.x >> e.y >> p.x >> p.y;

	if ((s.x == e.x) || (s.y == e.y)) // 출발지와 도착지가 같은 축 위에 존재한다면
	{
		if (((s.x == e.x) && (e.x == p.x)) || ((s.y == e.y) && (e.y == p.y))) // 그리고 방해물도 같은 축 위에 존재한다면
		{
			if (((s.x < p.x) && (p.x < e.x)) || ((s.x > p.x) && (p.x > e.x)) ||
				((s.y < p.y) && (p.y < e.y)) || ((s.y > p.y) && (p.y > e.y))) // 출발지와 도착지 사이에 방해물이 있는 경우
				cout << 2;
			else
				cout << 0;
		}
		else // 출발지와 도착지가 같은 축 위에 존재하고 방해물은 그 축 위에 없는 경우
			cout << 0;
	}
	else
		cout << 1;
}