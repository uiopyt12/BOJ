#include <bits/stdc++.h>


int abc1[26];
int abc2[26]; 

int main()
{
  int n;
  std::cin >> n;

  std::string str1, str2;

  for (int i=0; i<n; i++){
    std::cin >> str1 >> str2;
    for (int j=0; j<26; j++) //초기화
      abc1[j] = abc2[j] = 0;
    

    for (int j=0; j<str1.size(); j++)
      abc1[str1[j]-'a']++;
    for (int j=0; j<str2.size(); j++)
      abc2[str2[j]-'a']++;


    for (int j=0; j<26; j++){
      if (abc1[j] != abc2[j]){
        std::cout << "Impossible" << '\n';
        break;
      }
      else if (j == 25)
        std::cout << "Possible" << '\n';
    }


  }
}
/*
각 문자의 인덱스합을 통해 판단하면 strfry를 통해 나올 수 있는 문자열을 찾아낼 수 있지만
ad 와 bc처럼 strfry를 통해 나올 수 없는 문자열도 가능하게 판단하기 때문에 옳지 않다.
*/

