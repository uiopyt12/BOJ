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
    if (*phead  == NULL){//�ƿ� ����ִ� ���(��� ��쿡 ����ؾ� �Ѵ�.)
        newnode->link = NULL;
        *phead = newnode;
    }
    else if (p = NULL){//������ �� ���� ��尡 ����ִ�, ��, �� ó���� ���� ��
        newnode->link = *phead;
        *phead = newnode;
    }
    else{//�Ϲ����� ���
        newnode->link = p->link; // ������ �� ������ ������ ��� ����ų �� �� �� ����
        p->link = newnode;
    }
}

void removenode (Listnode **phead, Listnode * p){//�����ϴ� �� ��带 �޾ƾ� ����
    Listnode * temp; // ���� ����Ʈ�� �� ����Ű�� ���� �ӽ÷� ����� ����

    if (p == NULL){ // �� �� ��带 ����
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