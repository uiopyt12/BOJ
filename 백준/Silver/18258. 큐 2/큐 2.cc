#include <bits/stdc++.h>
using namespace std;


int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;


        queue<int> q;
        string com;
        int x;
        while (n--)
        {
                cin >> com;
                if (com.compare("push") == 0)
                {
                        cin >> x;
                        q.push(x);
                }

                else if (com.compare("pop") == 0)
                {
                        if (q.empty())
                                cout << -1 << '\n';
                        else
                        {
                                cout << q.front() << '\n';
                                q.pop();
                        }
                }
                else if (com.compare("size") == 0)
                        cout << q.size() << '\n';

                else if (com.compare("empty") == 0)
                {
                        if (q.empty())
                                cout << 1 << '\n';
                        else
                                cout << 0 << '\n';
                }

                else if (com.compare("front") == 0)
                {
                        if (q.empty())
                                cout << -1 << '\n';
                        else
                                cout << q.front() << '\n';
                }

                else if (com.compare("back") == 0)
                {
                        if (q.empty())
                                cout << -1 << '\n';
                        else
                                cout << q.back() << '\n';
                }
        }

        return 0;
}