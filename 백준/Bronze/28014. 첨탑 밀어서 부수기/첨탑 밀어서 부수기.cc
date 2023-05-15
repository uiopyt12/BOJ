#include <bits/stdc++.h>


int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    
    int n;
    std::cin >> n;

    int now=0, pre;
    int frequency=0;
    while(n--){
        pre = now;
        std::cin >> now;
        if (pre <= now)
            frequency++;
    }

    std::cout << frequency;
}