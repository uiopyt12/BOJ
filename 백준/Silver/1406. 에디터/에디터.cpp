#include <bits/stdc++.h>


int main()
{
  std::string str1;
  std::cin >> str1;
  std::list<char> lst(str1.begin(), str1.end());
  std::list<char>::iterator iter = lst.end();

  int m;
  std::cin >> m;
  char command;
  char buffer;
  
  for (int i=0; i<m; i++){
    std::cin >> command;

    if (command == 'L' && iter != lst.begin())
      iter--;
    else if (command == 'D' && iter != lst.end())
      iter++;
    else if (command == 'P'){
      std::cin >> buffer;
      lst.insert(iter, buffer);
    } 
    else if (command == 'B' && iter != lst.begin()){
      iter--;
      iter = lst.erase(iter);
    }
  }



  for (iter=lst.begin(); iter != lst.end(); iter++)
    std::cout << *iter;
  
    
}
