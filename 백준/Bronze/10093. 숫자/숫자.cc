#include <bits/stdc++.h>


int main()
{
  long long a,b;
  std::cin >> a >> b;

  if (a == b)
    std::cout << 0;

  else {
    if (a>b){
      int temp = b;
      b = a;
      a = temp;
    }
      
    a++;
    std::cout << b-a << '\n';
    while (a < b)
    std::cout << (a++) << ' ';
  }
  
}