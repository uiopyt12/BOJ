#include <bits/stdc++.h>


int main()
{
    int L,P;
    std::cin >> L >> P;

    int temp;
    for (int i=0; i<5; i++){
        std::cin >> temp;
        std::cout << temp - L*P << ' ';
    }
}
