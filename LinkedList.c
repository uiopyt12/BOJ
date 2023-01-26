#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode{
    char data;
    struct Listnode * link;
} Listnode;

void printnode(Listnode * r){
    while (r != NULL){
        printf("%c", r->data);
        r = r->link;
    }
}

void insertnode(Listnode **phead, Listnode *p, Listnode *newnode){
    if (*phead  == NULL){//아예 비어있는 경우(모든 경우에 대비해야 한다.)
        newnode->link = NULL;
        *phead = newnode;
    }
    else if (p = NULL){//삽입할 곳 전의 노드가 비어있는, 즉, 맨 처음에 넣을 때
        newnode->link = *phead;
        *phead = newnode;
    }
    else{//일반적인 경우
        newnode->link = p->link; // 순서를 잘 맞추지 않으면 어디를 가리킬 지 알 수 없음
        p->link = newnode;
    }
}

void removenode (Listnode **phead, Listnode * p){//삭제하는 앞 노드를 받아야 편함
    Listnode * temp; // 다음 리스트를 잘 가리키기 위해 임시로 만들어 놓음

    if (p == NULL){ // 맨 앞 노드를 삭제
        temp = *phead;
        *phead = temp->link;
        free(temp);
    }
    else{
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }

}

int main()
{
    Listnode * head;
    Listnode * p1, * p2, * p3;

    p1 = (Listnode *) malloc(sizeof(Listnode));
    p2 = (Listnode *) malloc(sizeof(Listnode));
    p3 = (Listnode *) malloc(sizeof(Listnode));

    p1->data = 'a';
    p2->data = 'b';
    p3->data = 'c';

    head = p1;
    p1->link = p2;
    p2->link = p3;
    p3->link = NULL;

    removenode(&head, p1);
    printnode(head);
}