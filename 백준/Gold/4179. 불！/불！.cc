#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second


string maze[1001];
int fire[1001][1001];
int jihun[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{
        int r,c;
        cin >> r >> c;
        for (int i=0; i<r; i++)
        {
                cin >> maze[i];
        }


        queue<pair<int,int>> Q;
        for (int i=0; i<r; i++)
        {
                for (int j=0; j<c; j++)
                {
                        if (maze[i][j] == 'F')
                        {
                                fire[i][j] = 1;
                                Q.push({i,j});

                        }
                }
        }

        while (!Q.empty())
        {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i=0; i<4; i++)
                {
                        int nx = cur.x + dx[i];
                        int ny = cur.y + dy[i];
                        if (!(nx<0 || nx>=r || ny<0 || ny>=c) && maze[nx][ny]=='.' && fire[nx][ny]==0)
                        {
                                fire[nx][ny] = fire[cur.x][cur.y]+1;
                                Q.push({nx, ny});
                        }//if
                }//for

        }//while







        for (int i=0; i<r; i++)
        {
                for (int j=0; j<c; j++)
                {
                        if (maze[i][j] == 'J')
                        {
                                jihun[i][j] = 1;
                                Q.push({i,j});

                        }
                }
        }

        while (!Q.empty())
        {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i=0; i<4; i++)
                {
                        int nx = cur.x + dx[i];
                        int ny = cur.y + dy[i];
                        if (!(nx<0 || nx>=r || ny<0 || ny>=c) && maze[nx][ny]=='.' && jihun[nx][ny]==0)
                        {
                                jihun[nx][ny] = jihun[cur.x][cur.y]+1;
                                Q.push({nx, ny});
                        }//if
                }//for
        }//while





        int mn=4955;
        for (int i=0; i<r; i++)
        {
                if (fire[i][0] == 0)
                        fire[i][0] = 4955;
                if (fire[i][c-1] == 0)
                        fire[i][c-1] = 4955;
                if ((jihun[i][0]!=0) && (jihun[i][0] < fire[i][0]))
                {
                        mn = min(mn, jihun[i][0]);
                }
                else if ((jihun[i][c-1]!=0) && (jihun[i][c-1] < fire[i][c-1]))
                {
                        mn = min(mn, jihun[i][c-1]);
                }
        }


        for (int j=0; j<c; j++)
        {
                if (fire[0][j] == 0)
                        fire[0][j] = 4955;
                if (fire[r-1][j] == 0)
                        fire[r-1][j] = 4955;
                if ((jihun[0][j]!=0) && (jihun[0][j] < fire[0][j]))
                {
                        mn = min(mn, jihun[0][j]);
                }
                else if ((jihun[r-1][j]!=0) && (jihun[r-1][j] < fire[r-1][j]))
                {
                        mn = min(mn, jihun[r-1][j]);
                }
        }

    
        if (mn == 4955)
                cout << "IMPOSSIBLE";
        else
                cout << mn;
}
