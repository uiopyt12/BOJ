#include <bits/stdc++.h>


int main()
{
    int n;
    std::cin >> n;
    for (int i=0; i<2*n-1; i++){
        for (int j=0; j<abs(abs(n-1-i)-n+1); j++){
            std::cout << ' ';
        }
        
        for (int j=0; j<(2*n-1)-2*abs(abs(n-1-i)-n+1); j++){
            std::cout << '*';
        }

        if (i != 2*n-2)
            std::cout << '\n';
    }
}