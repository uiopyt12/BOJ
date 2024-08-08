#include <bits/stdc++.h>
using namespace std;

typedef struct coord
{
	int z, y, x;
}coord;

coord d[6] = {
	{0,0,1},
	{0,0,-1},
	{0,1,0}, 
	{0,-1,0},
	{1,0,0},
	{-1,0,0}
};

int main()
{
	int l, r, c;
	
	while (true)
	{
		cin >> l >> r >> c;
		if (l == 0) break;

		vector<vector<vector<char>>> building(l, vector<vector<char>>(r, vector<char>(c, '.')));
		vector<vector<vector<int>>> dist(l, vector<vector<int>>(r, vector<int>(c)));
		queue<coord> q;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						q.push({ i,j,k });
					}
				}
			}
		}

		int ans = 32768;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int nz = cur.z + d[dir].z;
				int ny = cur.y + d[dir].y;
				int nx = cur.x + d[dir].x;
				if (nz < 0 || nz >= l || ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (dist[nz][ny][nx] != 0) continue;
				if (building[nz][ny][nx] == '#') continue;
				if (building[nz][ny][nx] == 'E') ans = dist[cur.z][cur.y][cur.x] + 1;
				dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
				q.push({ nz,ny,nx });
			}
		}
		
		if (ans == 32768)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << ans << " minute(s).\n";		
	}

}