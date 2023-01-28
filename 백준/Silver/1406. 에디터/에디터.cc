#include <bits/stdc++.h>

const int MX = 1000*100*6+1;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1; // 아직 사용하지 않은, 즉 앞으로 삽입할  원소의 인덱스


void insert(int addr, int num){
  dat[unused] = num;
  nxt[unused] = nxt[addr];
  if (nxt[unused] != -1) // 다음 노드가 없는 경우, 즉 마지막에 삽입하는 경우 nxt[unused]가 -1이 된다.
    pre[nxt[unused]] = unused; // 다음 노드가 없는 경우에는 건너뛴다.  
  nxt[addr] = unused;
  pre[unused] = addr;
  unused++;
}

void erase(int addr){  
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1) // 다음 노드가 없는 경우, 즉 마지막 노드를 삭제하는 경우가 아니라면 건너뛴다.
    pre[nxt[addr]] = pre[addr]; // 다음 노드가 없는 경우에는 건너뛴다.
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    std::cout << dat[cur];
    cur = nxt[cur];
  }
  std::cout << "\n";
}

int main()
{
  std::fill(pre, pre+MX, -1);
  std::fill(nxt, nxt+MX, -1);


  std::string str1;
  std::cin >> str1;

  int cursor=0;
  while (str1[cursor] != '\0'){
    insert(cursor, str1[cursor]);
    cursor++;
  }

  int m;
  char data;
  std::cin >> m;
  char command;
  for (int i=0; i<m; i++){
    std::cin >> command;
    if (command == 'L' && pre[cursor] != -1)
      cursor = pre[cursor];
    
    else if (command == 'D' && nxt[cursor] != -1)
      cursor = nxt[cursor];

    else if (command == 'B' && pre[cursor] != -1){
      erase(cursor);
      cursor = pre[cursor];
    }
      
    else if (command == 'P'){
      std::cin >> data;
      insert(cursor, data);
      cursor = nxt[cursor];
    }
  }

  traverse();

  


}


