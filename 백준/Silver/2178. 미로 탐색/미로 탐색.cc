#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int maze[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
        int n,m;
        cin >> n >> m;

        char temp;
        for (int row=0; row<n; row++)
        {
                for (int col=0; col<m; col++)
                {
                        cin >> temp;
                        maze[row][col] = temp-'0';
                }

        }


        queue<pair<int,int>> Q;
        int dist=1;
        Q.push({0, 0});

        vis[0][0] = 1;


        while (!Q.empty())
        {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i=0; i<4; i++)
                {
                        int nx = cur.x + dx[i];
                        int ny = cur.y + dy[i];
                        if (!(nx<0 || nx>=n || ny<0 || ny>=m) && vis[nx][ny]==0 && maze[nx][ny]==1)
                        {
                                vis[nx][ny] = vis[cur.x][cur.y]+1;
                                Q.push({nx, ny});
                        }//if
                }//for

        }//while


        cout << vis[n-1][m-1];


}
