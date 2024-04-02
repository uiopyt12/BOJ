#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int tomato[1001][1001];
int vis[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
        int m,n;
        cin >> m >> n;


        queue<pair<int,int>> Q;
        for (int row=0; row<n; row++)
        {
                for (int col=0; col<m; col++)
                {
                        cin >> tomato[row][col];
                        if (tomato[row][col] == 1)
                        {
                                Q.push({row, col});
                                vis[row][col] = 1;
                        }
                        else if (tomato[row][col] == -1)
                                vis[row][col] = -1;


                }

        }
    
        while (!Q.empty())
        {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i=0; i<4; i++)
                {
                        int nx = cur.x + dx[i];
                        int ny = cur.y + dy[i];
                        if (!(nx<0 || nx>=n || ny<0 || ny>=m) && vis[nx][ny]==0 && tomato[nx][ny]==0)
                        {
                                vis[nx][ny] = vis[cur.x][cur.y]+1;
                                Q.push({nx, ny});
                        }//if
                }//for

        }//while



        int mx=0;
        for (int i=0; i<n; i++)
        {
                for (int j=0; j<m; j++)
                {
                        mx = max(mx, vis[i][j]);

                        if (vis[i][j] == 0)
                        {
                                cout << -1;
                                return 0;
                        }
                }
        }

        if (mx == 1)
                cout << 0;
        else
                cout << mx-1;

}