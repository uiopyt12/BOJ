#include <bits/stdc++.h>
using namespace std;

bool RisEscaped, BisEscaped;
int n, m;

void tiltBoard(int dir, char board[10][10], int rR, int cR, int rB, int cB)
{
        RisEscaped = false;
        BisEscaped = false;

        int tmp;
        switch (dir)
        {
        case 0: // 오른쪽
                if (cR < cB) // 파란공이 더 오른쪽에 있는 경우
                {
                        tmp = cB; // 파란공 먼저 옮김
                        cB++;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                }
                                cB++;
                        }
                        cB--;
                        if (BisEscaped == false)
                                swap(board[rB][tmp], board[rB][cB]);


                        tmp = cR; // 빨간공 옮김
                        cR++;
                        while ((board[rR][cR] != '#') && (board[rR][cR] != 'B'))
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR++;
                        }
                        cR--;
                        if (RisEscaped == false)
                                swap(board[rR][tmp], board[rR][cR]);
                }
                else if (cR > cB) // 빨간공이 더 오른쪽에 있는 경우
                {
                        tmp = cR; // 빨간공 먼저 옮김
                        cR++;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR++;
                        }
                        cR--;
                        if (RisEscaped == false)
                                swap(board[rR][tmp], board[rR][cR]);

                        tmp = cB; // 파란공 옮김
                        cB++;
                        while ((board[rB][cB] != '#') && (board[rB][cB] != 'R'))
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                        ;
                                }
                                cB++;
                        }
                        cB--;
                        if (BisEscaped == false)
                                swap(board[rB][tmp], board[rB][cB]);

                }
                else if (cR == cB) // 다른 행에 있는 경우
                {
                        tmp = cR; // 빨간공 옮김
                        cR++;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR++;
                        }
                        cR--;
                        if (RisEscaped == false)
                        swap(board[rR][tmp], board[rR][cR]);

                        tmp = cB; // 파란공 옮김
                        cB++;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                        ;
                                }
                                cB++;
                        }
                        cB--;
                        if (BisEscaped == false)
                        swap(board[rB][tmp], board[rB][cB]);
                }

                break;

        case 1: // 아래
                if (rR < rB) // 파란공이 더 아래에 있는 경우
                {
                        tmp = rB; // 파란공 먼저 옮김
                        rB++;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB++;
                        }
                        rB--;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);


                        tmp = rR; // 빨간공 옮김
                        rR++;
                        while ((board[rR][cR] != '#') && (board[rR][cR] != 'B'))
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR++;
                        }
                        rR--;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);
                }
                else if (rR > rB) // 빨간공이 더 아래에 있는 경우
                {
                        tmp = rR; // 빨간공 옮김
                        rR++;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR++;
                        }
                        rR--;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);


                        tmp = rB; // 파란공 먼저 옮김
                        rB++;
                        while ((board[rB][cB] != '#') && (board[rB][cB] != 'R'))
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB++;
                        }
                        rB--;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);
                }
                else if (rR == rB) // 다른 열에 있는 경우
                {
                        tmp = rR; // 빨간공 옮김
                        rR++;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR++;
                        }
                        rR--;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);


                        tmp = rB; // 파란공 옮김
                        rB++;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB++;
                        }
                        rB--;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);
                }

                break;

        case 2: // 왼쪽
                if (cR < cB) // 빨간공이 더 왼쪽에 있는 경우
                {
                        tmp = cR; // 빨간공 먼저 옮김
                        cR--;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR--;
                        }
                        cR++;
                        if (RisEscaped == false)
                        swap(board[rR][tmp], board[rR][cR]);

                        tmp = cB; // 파란공 옮김
                        cB--;
                        while ((board[rB][cB] != '#') && (board[rB][cB] != 'R'))
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                        ;
                                }
                                cB--;
                        }
                        cB++;
                        if (BisEscaped == false)
                        swap(board[rB][tmp], board[rB][cB]);
                }
                else if (cR > cB) // 파란공이 더 왼쪽에 있는 경우
                {
                        tmp = cB; // 파란공 먼저 옮김
                        cB--;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                        ;
                                }
                                cB--;
                        }
                        cB++;
                        if (BisEscaped == false)
                        swap(board[rB][tmp], board[rB][cB]);


                        tmp = cR; // 빨간공 옮김
                        cR--;
                        while ((board[rR][cR] != '#') && (board[rR][cR] != 'B'))
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR--;
                        }
                        cR++;
                        if (RisEscaped == false)
                        swap(board[rR][tmp], board[rR][cR]);
                }
                else if (cR == cB) // 다른 행에 있는 경우
                {
                        tmp = cR; // 빨간공 옮김
                        cR--;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[rR][tmp] = '.';
                                        ;
                                }
                                cR--;
                        }
                        cR++;
                        if (RisEscaped == false)
                        swap(board[rR][tmp], board[rR][cR]);

                        tmp = cB; // 파란공 옮김
                        cB--;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[rB][tmp] = '.';
                                }
                                cB--;
                        }
                        cB++;
                        if (BisEscaped == false)
                        swap(board[rB][tmp], board[rB][cB]);
                }

                break;

        case 3: // 위
                if (rR > rB) // 파란공이 더 위에 있는 경우
                {
                        tmp = rB; // 파란공 먼저 옮김
                        rB--;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB--;
                        }
                        rB++;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);


                        tmp = rR; // 빨간공 옮김
                        rR--;
                        while ((board[rR][cR] != '#') && (board[rR][cR] != 'B'))
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR--;
                        }
                        rR++;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);
                }
                else if (rR < rB) // 빨간공이 더 위에 있는 경우
                {
                        tmp = rR; // 빨간공 옮김
                        rR--;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR--;
                        }
                        rR++;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);


                        tmp = rB; // 파란공 먼저 옮김
                        rB--;
                        while ((board[rB][cB] != '#') && (board[rB][cB] != 'R'))
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB--;
                        }
                        rB++;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);
                }
                else if (rR == rB) // 다른 열에 있는 경우
                {
                        tmp = rR; // 빨간공 옮김
                        rR--;
                        while (board[rR][cR] != '#')
                        {
                                if (board[rR][cR] == 'O')
                                {
                                        RisEscaped = true;
                                        board[tmp][cR] = '.';
                                }
                                rR--;
                        }
                        rR++;
                        if (RisEscaped == false)
                        swap(board[tmp][cR], board[rR][cR]);


                        tmp = rB; // 파란공 옮김
                        rB--;
                        while (board[rB][cB] != '#')
                        {
                                if (board[rB][cB] == 'O')
                                {
                                        BisEscaped = true;
                                        board[tmp][cB] = '.';
                                }
                                rB--;
                        }
                        rB++;
                        if (BisEscaped == false)
                        swap(board[tmp][cB], board[rB][cB]);
                }

                break;
        }

}

void dfs(int depth, char paramBoard[10][10])
{
        if ((RisEscaped == true) && (BisEscaped == false))
        {
                cout << 1;
                exit(0);
        }
        else if (!(RisEscaped == false && BisEscaped == false))
        {
                return;
        }
        if (depth == 10)
        {

                return;
        }

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
                                {
                                        rR = a, cR = b;
                                }
                                else if (curBoard[a][b] == 'B') // 인자로 전달해주기 위한 파란 공의 좌표
                                {
                                        rB = a, cB = b;
                                }
                        }

                }

                tiltBoard(i, curBoard, rR, cR, rB, cB);

                dfs(depth + 1, curBoard);
        }

}

int main()
{
        char board[10][10];
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        cin >> board[i][j];
                }
        }


        dfs(0, board);


        if ((RisEscaped == true) && (BisEscaped == false))
                cout << 1;
        else
                cout << 0; // 탈출 불가
}