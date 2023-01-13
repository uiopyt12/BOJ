#include <bits/stdc++.h>


int card[20];

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
  for (int i=0; i<20; i++){
    card[i] = i+1;
  }

  int a,b;
  int temp;
  for (int i=0; i<10; i++){
    std::cin >> a >> b;
    int delta = b-a+1; //구간의 원소 개수

    for (int weight=0; weight<delta/2; weight++)
      swap(&card[a-1+weight], &card[b-1-weight]);
    
  }

  for (int i=0; i<20; i++)
    std::cout << card[i] << ' ';

}