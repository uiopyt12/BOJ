#include <bits/stdc++.h>


int main()
{
  int a,b,c;
  std::cin >> a >> b >> c;
  
  int s, m, l;
  if (a > b){
    if (b > c)
      l = a, m = b, s = c; 
    
    else if (a > c)
      l = a, m = c, s = b;
    
    else
      l = c, m = a, s = b;
  }
  else {
    if (c < a)
      l = b, m = a, s = c;

    else if (b > c)
      l = b, m = c, s = a;

    else
      l = c, m = b, s = a;
  }

  std::cout << s << ' ' << m << ' ' << l;
}