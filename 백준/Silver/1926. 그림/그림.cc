#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int paper[500][500];
int vis[500][500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
        int n,m;
        cin >> n >> m;

        int temp;
        for (int row=0; row<n; row++)
        {
                for (int col=0; col<m; col++)
                {
                        cin >> temp;
                        paper[row][col] = temp;
                }

        }



        queue<pair<int,int>> Q;
        int cnt=0, area, maxArea=0;

        for (int i=0; i<n; i++)
        {
                for (int j=0; j<m; j++)
                {
                        if (paper[i][j]==1 && vis[i][j]==0)
                        {
                                Q.push({i, j});
                                cnt++;

                                area=1;


                                while (!Q.empty())
                                {
                                        pair<int, int> cur = Q.front(); Q.pop();
                                        vis[cur.x][cur.y] = 1;


                                        for (int i=0; i<4; i++)
                                        {
                                                int nx = cur.x + dx[i];
                                                int ny = cur.y + dy[i];
                                                if (!(nx<0 || nx>=n || ny<0 || ny>=m) && vis[nx][ny] != 1  && paper[nx][ny] == 1)
                                                {
                                                        vis[nx][ny] = 1;
                                                        Q.push({nx, ny});
                                                        area++;
                                                }
                                        }
                                }
                                if (area > maxArea)
                                        maxArea = area;
                        }

                }
        }


        cout << cnt << endl << maxArea;





}
