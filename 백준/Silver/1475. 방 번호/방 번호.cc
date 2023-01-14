#include <bits/stdc++.h>



char num[9]; //인덱스와 숫자가 같음에 유의
int main()
{
  char input[8];
  std::cin >> input;


  int numSet=0;
  for (int i=0; i<strlen(input); i++){
    if (input[i] == '9')
      input[i] = '6'; 
    
    if (num[(input[i]-'0')] == 0){
      for (int i=0; i<9; i++)
        num[i]++;
      num[6]++, numSet++;
    }

    num[(input[i]-'0')]--;

  }


  std::cout << numSet;
}