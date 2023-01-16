#include <bits/stdc++.h>

int xum[2*1000*1000+1];
int main()
{
  int n;
  std::cin >> n;

  int temp;
  for (int i=0; i<n; i++){
    std::cin >> temp;
    xum[temp]++;
  }

  int x;
  std::cin >> x;

  int idx=1, cnt=0;
  while (n && idx < x){
    if (xum[idx]){
      xum[idx]--;
      n--;
      if (xum[x-idx]){ // x-idx > 0
        xum[x-idx]--;
        n--;
        cnt++;
      }
    }
    
    idx++;
  }

  std::cout << cnt;
}