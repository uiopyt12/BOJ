#include <bits/stdc++.h>


int main()
{
  int i,o;
  int current=0,best=0;
  for (int j=0; j<4; j++){
    std::cin >> o >> i;
    current -= o;
    current += i;
    if (current > best) best = current;
  }

  std::cout << best;
}