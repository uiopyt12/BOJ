  #include <bits/stdc++.h>
  #define MAX 1000*1000*1000+1

  typedef struct orderStack{
    int data;
    int order;
  } orderStack;

  int main()
  {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::stack<orderStack> tmxor;
    int order=0;
    tmxor.push({MAX, order});

    int n;
    std::cin >> n;

    int height;
    while (n--){
      std::cin >> height;
      while (height >= tmxor.top().data)
        tmxor.pop();
      
      std::cout << tmxor.top().order << ' ';

      order++;
      tmxor.push({height, order});
    }
    
  }