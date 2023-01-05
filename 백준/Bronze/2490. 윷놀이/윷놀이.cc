#include <bits/stdc++.h>


int main()
{
  int a,b,c,d;

  int sum;
  for (int i=0; i<3; i++){
    std::cin >> a >> b >> c >> d;
    sum = a+b+c+d;
    if (sum == 0)
      std::cout << 'D' << '\n';
    if (sum == 1)
      std::cout << 'C' << '\n';
    if (sum == 2)
      std::cout << 'B' << '\n';
    if (sum == 3)
      std::cout << 'A' << '\n';
    if (sum == 4)
      std::cout << 'E' << '\n';
    
  }
}