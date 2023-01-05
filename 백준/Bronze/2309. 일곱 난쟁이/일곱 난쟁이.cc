#include <bits/stdc++.h>


int height[9];
int main()
{
  int sum=0;
  for (int i=0; i<9; i++){
    std::cin >> height[i];
    sum += height[i];
  }

  
  for (int i=0; i<8; i++){
    for (int j=i+1; j<9; j++){
      if (sum-(height[i] + height[j]) == 100){
        height[i] = 101, height[j] = 101;
        i=8, j=9;
      }
    }
  }



  int smallest, smallIndex;
  for (int i=0; i<7; i++){
    smallest = 101;
    for (int j=0; j<9; j++){
      if (height[j] < smallest)
        smallest = height[j], smallIndex = j;
    }
    std::cout << smallest << '\n';
    height[smallIndex] = 101;
  }
}