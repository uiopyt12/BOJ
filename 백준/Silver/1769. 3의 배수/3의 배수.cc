#include <bits/stdc++.h>


int sumofdigit(int n)
{
    int output = 0;
    while (n>=10)
    {
        output += n%10; // 1의 자리 수를 더해주고
        n /= 10; // 자리수를 감소시키고, 정수로 형변환
    }
    output += n;

    return output;
}


int main()
{
    std::string x;
    std::cin >> x;

    int sum=0;
    int cnt=0;

    if (x.length() == 1)
        cnt = 0;
    else
        cnt++;

    for (int i=0; i<x.size(); i++)
    {
        sum += (x[i]-'0');
    }

    while (sum >= 10)
    {
        sum = sumofdigit(sum);
        cnt++;
    }

    std::cout << cnt << '\n';

    if (sum%3 == 0)
        std::cout << "YES";
    else
        std::cout << "NO";
}