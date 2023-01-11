#include <bits/stdc++.h>


int main()
{
  int n;
  std::cin >> n;

  int time, temp;
  int y=0, m=0;
  for (int i=0; i<n; i++){
    std::cin >> time;


    temp = time;
    while (temp >= 30){
      y += 10;
      temp -= 30;
    }
    y += 10;
    
    temp = time;
    while (temp >= 60){
      m += 15;
      temp -= 60;
    }
    m += 15;
  }

  if (y == m){
    std::cout << 'Y' << ' ' << 'M' << ' ' << y; 
  }
  
  else if (y < m){
    std::cout << 'Y' << ' ' << y;
  }

  else {
    std::cout << 'M' << ' ' << m;
  }

  
}