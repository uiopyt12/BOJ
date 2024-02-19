#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,k;
    cin >> n >> m;

    int basket[n] = {0};
    while (m--)
    {
       cin >> i >> j >> k; 
       for (int idx=i; idx<=j; idx++)
       {
        basket[idx-1] = k;
       }

    }

    for (int idx=0; idx<n; idx++)
        cout << basket[idx] << ' ';

}