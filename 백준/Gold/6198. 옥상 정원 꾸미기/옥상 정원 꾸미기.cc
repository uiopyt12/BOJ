#include <bits/stdc++.h>


int main()
{
  std::stack<int> tmxor;

  int n;
  std::cin >> n;

  int height;
  unsigned int total=0;
  for (int i=0; i<n; i++){
    std::cin >> height;


    while (!tmxor.empty() && height >= tmxor.top())
      tmxor.pop();
      
    total += tmxor.size();
    tmxor.push(height);      
  }


  std::cout << total;
}