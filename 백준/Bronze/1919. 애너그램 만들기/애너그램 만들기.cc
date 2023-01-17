#include <bits/stdc++.h>


int str1[26], str2[26];
int main()
{
  std::string temp;
  std::cin >> temp;
  for (int i=0; i<temp.length(); i++){
    str1[temp[i]-'a']++; 
  }
  std::cin >> temp;
  for (int i=0; i<temp.length(); i++){
    str2[temp[i]-'a']++; 
  }

  int ans=0;
  for (int i=0; i<26; i++){
    ans += abs(str1[i]-str2[i]);
  }

  
  std::cout << ans;
}