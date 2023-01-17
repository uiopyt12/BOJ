#include <bits/stdc++.h>

int room[2][6];
int main()
{
  int n,k;
  std::cin >> n >> k;

  int sex, age;
  for (int i=0; i<n; i++){
    std::cin >> sex >> age;
    room[sex][age-1]++;
  }

  int ans=0;
  for (int i=0; i<2; i++){
    for (int j=0; j<6; j++){
      if (room[i][j]%k){
        ans += (room[i][j]/k) + 1;
      }
      else // 0명이어도 그냥 더해주면 됨
        ans += room[i][j]/k;
    }
  }
  

  std::cout << ans;
}