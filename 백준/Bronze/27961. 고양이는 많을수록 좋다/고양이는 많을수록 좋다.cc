#include <bits/stdc++.h>


int main()
{
    double n;
    std::cin >> n;
    if (!n) std::cout << 0;
    else std::cout << ceil(log2(n))+1;
}