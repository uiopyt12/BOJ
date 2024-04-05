#include <bits/stdc++.h>
using namespace std;


#define osatsu 495549
int road[100001];

int main()
{
        int n,k;
        cin >> n >> k;

        for (int i=0; i<100001; i++)
                road[i] = osatsu;

        road[k] = osatsu*2;

        queue<int> q;
        int cur=n;
        road[cur] = 0;
        q.push(cur);
        while (road[k]==osatsu*2)
        {
                cur = q.front(), q.pop();
                if (cur+1 <= 100000)
                {
                        if (road[cur]+1 < road[cur+1])
                        {
                                q.push(cur+1);
                                road[cur+1] = road[cur]+1;
                        }

                }
                if (cur-1 >= 0)
                {
                        if (road[cur]+1 < road[cur-1])
                        {
                                q.push(cur-1);
                                road[cur-1] = road[cur]+1;
                        }
                }
                if (cur*2 <= 100000)
                {
                        if (road[cur]+1 < road[cur*2])
                        {
                                q.push(cur*2);
                                road[cur*2] = road[cur]+1;
                        }
                }
        }// while


        //for (int i=0; i<=k; i++)
        //      cout << "road[" << i << "] : " << road[i] << endl ;
        cout << road[k];

}
