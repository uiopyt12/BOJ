#include <bits/stdc++.h>
using namespace std;


const int MX = 10005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
        head++;
        dat[head] = x;

}

void push_back(int x){
        dat[tail] = x;
        tail--;
}

int pop_front(){
        if (tail == head)
                return -1;

        return dat[head--];
}

int pop_back(){
        if (tail == head)
                return -1;

        return dat[++tail];

}
int size()
{
        return head-tail;
}

int empty()
{
        if (head == tail) return 1;
        else return 0;
}

int front(){
        if (empty()) return -1;
        return dat[head];
}

int back(){
        if (empty()) return -1;
        return dat[tail+1];
}


int main(void)
{
        int n;
        cin >> n;

        string com;
        int x;
        while (n--)
        {
            cin >> com;

            if (com == "push_front")
            {
                cin >> x;
                push_front(x);
            }
            else if (com == "push_back")
            {
                cin >> x;
                push_back(x);
            }
            else if (com == "pop_front")
                cout << pop_front() << endl;

            else if (com == "pop_back")
                cout << pop_back() << endl;

            else if (com == "size")
                cout << size() << endl;

            else if (com == "empty")
                cout << empty() << endl;

            else if (com == "front")
                cout << front() << endl;

            else if (com == "back")
                cout << back() << endl;

        }
}
