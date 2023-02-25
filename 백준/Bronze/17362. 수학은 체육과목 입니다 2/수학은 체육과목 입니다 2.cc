#include <bits/stdc++.h>


int main()
{
  int n;
  std::cin >> n;

  n %= 8;
  if (!n)
    n += 8;
  if (n == 8)
    n = 2;
  else if (n == 7)
    n = 3;
  else if (n == 6)
    n = 4;

  std::cout << n;
}