#include <bits/stdc++.h>


int main()
{
  int n;
  std::cin >> n;

  std::string inputStr;
  char c;
  for (int i=0; i<n; i++){
    std::cin >> inputStr;

    std::list<char> answer;
    std::list<char>::iterator cursor = answer.end();

    for (int j=0; j<inputStr.length(); j++){
      if (inputStr[j] == '<'){
        if (cursor != answer.begin())
          cursor--;
      }

      else if (inputStr[j] == '>'){
        if (cursor != answer.end())
          cursor++;
      }
        
      else if (inputStr[j] == '-'){
        if (cursor != answer.begin()){
          cursor--;
          cursor = answer.erase(cursor);
        }
      }

      else 
        answer.insert(cursor, inputStr[j]);
    }

    for (cursor=answer.begin(); cursor != answer.end(); cursor++)
      std::cout << *cursor;
    std::cout << '\n';
  }
}