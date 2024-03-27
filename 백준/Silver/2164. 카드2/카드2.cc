#include <bits/stdc++.h>
using namespace std;


int card[500001];

int main()
{
        card[0]=0, card[1]=1, card[2]=2, card[3]=2, card[4]=4, card[5]=2;
        int n;
        cin >> n;

        for (int i=6; i<=n; i++)
        {
                if (i%2 == 0) //even
                {
                        card[i] = card[i/2]*2;
                }
                else //odd
                {
                        if (card[i/2] == i/2)
                                card[i] = 2;
                        else
                                card[i] = 2 + (card[i/2]*2);
                }


        }
        printf("%d", card[n]);


        return 0;
}
