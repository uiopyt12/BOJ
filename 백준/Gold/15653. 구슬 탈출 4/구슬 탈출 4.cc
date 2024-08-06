#include <bits/stdc++.h>
using namespace std;

bool canEscape;
bool RisEscaped, BisEscaped;
int n, m;
int ans = 128;
int dist[100][100][100][100];

bool moveBall(int& r, int& c, int dr, int dc, char(&board)[10][10])
{
        int nr = r, nc = c; // new row->nr, delta row->dr
        while ((board[nr + dr][nc + dc] != '#') && (board[nr + dr][nc + dc] != 'R') && (board[nr + dr][nc + dc] != 'B')) {
                nr += dr;
                nc += dc;
                if (board[nr][nc] == 'O') {
                        board[r][c] = '.';
                        r = nr;
                        c = nc;
                        return true;
                }
        }
        if (board[nr][nc] != 'O') {
                std::swap(board[r][c], board[nr][nc]);
                r = nr;
                c = nc;
        }
        return false;
}

void tiltBoard(int dir, char(&board)[10][10], int& rR, int& cR, int& rB, int& cB)
{
        RisEscaped = false;
        BisEscaped = false;
        canEscape = false;

        int dr = 0, dc = 0;
        if (dir == 0) dc = 1;  // 오른쪽
        if (dir == 1) dr = 1;  // 아래
        if (dir == 2) dc = -1; // 왼쪽
        if (dir == 3) dr = -1; // 위

        if ((dir == 0 && cR > cB) || (dir == 1 && rR > rB) ||
                (dir == 2 && cR < cB) || (dir == 3 && rR < rB)) {
                RisEscaped = moveBall(rR, cR, dr, dc, board);
                BisEscaped = moveBall(rB, cB, dr, dc, board);
        }
        else {
                BisEscaped = moveBall(rB, cB, dr, dc, board);
                RisEscaped = moveBall(rR, cR, dr, dc, board);
        }

        if (RisEscaped == true && BisEscaped == false)
                canEscape = true;
}

void dfs(int depth, char paramBoard[10][10])
{
        if (depth == 30) return;

        char curBoard[10][10];
        for (int i = 0; i < 4; i++)
        {
                int rR, cR, rB, cB;
                for (int a = 0; a < n; a++)
                {
                        for (int b = 0; b < m; b++)
                        {
                                curBoard[a][b] = paramBoard[a][b];
                                if (curBoard[a][b] == 'R') // 인자로 전달해주기 위한 빨간 공의 좌표                               
                                        rR = a, cR = b;
                                else if (curBoard[a][b] == 'B') // 인자로 전달해주기 위한 파란 공의 좌표
                                        rB = a, cB = b;
                        }
                }

                tiltBoard(i, curBoard, rR, cR, rB, cB);
                if (canEscape)
                {
                        ans = min(ans, depth + 1);
                }
                if (dist[rR][cR][rB][cB]!=0 && dist[rR][cR][rB][cB] < depth) continue;
                dist[rR][cR][rB][cB] = depth;

                // for문 안에서 돌다가 탈출해서 R과  B를 찾지 못해 rR, rC, rB, rB값이 쓰레기값이 들어갈 수 있다.
                // 이를 방지하기 위한 조건 검사
                if (!(canEscape == true || BisEscaped == true)) dfs(depth + 1, curBoard);
        }

}

int main()
{
        char board[10][10];
        cin >> n >> m;
        int rR, cR, rB, cB;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        cin >> board[i][j];
                        if (board[i][j] == 'R') // 인자로 전달해주기 위한 빨간 공의 좌표                               
                                rR = i, cR = j;
                        else if (board[i][j] == 'B') // 인자로 전달해주기 위한 파란 공의 좌표
                                rB = i, cB = j;
                }
        }
        dist[rR][cR][rB][cB] = 1;


        dfs(2, board);


        if (ans == 128)
                cout << -1;
        else
                cout << ans-2;
}