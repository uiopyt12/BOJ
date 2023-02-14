#include <bits/stdc++.h>


int main()
{
  int n;
  std::cin >> n;
  std::stack<int> tmxor;

  std::string ans;
  int temp, cnt=1;


  tmxor.push(0); // 비어있을 때 tmxor.top()을 처리하기 위함
  for (int i=0; i<n; i++){
    std::cin >> temp;


    if (temp > tmxor.top()){
      if (temp <= cnt-1){
        ans = "NO";
        break;
      }

      while (temp >= cnt){
        tmxor.push(cnt++);
        ans += "+\n";
      }
      tmxor.pop();
      ans += "-\n";      
    }

    else if (temp == tmxor.top()){
      tmxor.pop();
      ans += "-\n";
    }

    else { // temp < tmxor.top
      ans = "NO";
      break;
    }
    

  }


  std::cout << ans;
}