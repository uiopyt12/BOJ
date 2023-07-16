#include <bits/stdc++.h>


int main()
{
    int Lmax=0, Rmax=0, max=0, input, n;

    std::cin >> n;
    while (n--)
    {
        std::cin >> input;
        if (input == 1) Lmax++, Rmax--;
        else Lmax--, Rmax++;
        
        if (max < Lmax || max < Rmax)
            max = (Lmax > Rmax) ? Lmax : Rmax;
        if (Lmax < 0)
            Lmax = 0;
        if (Rmax < 0)
            Rmax = 0;
    }
    std::cout << max;
}

/*
1과 2로 이루어진 구간에서 연속으로 색칠하여 abs(1의 개수 - 2의 개수)의 최대값을 구하는 프로그램
Lmax와 Rmax를 통해 석상을 한 번씩만 지나간다. 반대편 석상이 입력으로 들어오면 Lmax나 Rmax가 1 감소된다.
그러다가 음수가 되면 음수인 구간은 abs가 최대값인 구간에 포함되지 않으므로 다시 0으로 초기화 해준다.
Lmax 혹은 Rmax가 양수라면 그 구간은 abs가 최대값인 구간에 포함될 수 있으므로 계속 진행한다.
석상을 한 번씩 훑고 지나가므로 O(n)의 시간복잡도를 가질 것 같다.
*/