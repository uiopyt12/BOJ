#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxStackSize 10000 //최대 스택 크기로 스택 크기를 나타냄
//배열을 통한 스택 구현이고, 크기변경이 불가능

typedef struct stack{
    int data[MaxStackSize];
    int top;
} stack;

void init(stack *s){//주소값을 복사해와야 값에 접근해 바꿀 수 있음(아마?)
    s->top = -1; //스택의 바닥은 -1
}

int is_empty(stack *s){//비어있는지 확인
    return (s->top == -1); //top이 -1이면 1을 아니면 0을 반환
}

int is_full(stack *s){//가득 차있는지 확인
    return (s->top == MaxStackSize-1); // top이 스택 크기 -1(최대 스택 크기)와 같으면 1, 아니면 0 반환
} 

void push(stack *s, int n){//가득 차있지 않을 때 원소를 삽입
    if (is_full(s)) //가득 차있으면 
        printf("-1\n");//오류 발생 
        //exit(1)을 통해 종료할 수 있음, 그러면 밑의 else는 제거해도 됨
    //가득 차있지 않으면
    else s->data[++(s->top)] = n; //전위 연산자를 통해 top을 하나 증가시킨 후의 인덱스에 n 삽입
}

int pop(stack *s){//top의 원소를 제거하고 그 원소를 반환
    if (is_empty(s)) //비어있으면
        return -1; //오류 발생, -1이 맨 위의 원소인 것과 오류인 것과 구분이 안될 수 있음
    //비어있지 않으면
    else return s->data[(s->top)--]; //후위 연산자를 통해 data의 top번째 원소를 반환하고 top의 값을 감소
}

void peek(stack *s){//top의 원소를 확인
    if (is_empty(s)) //비어있으면
        printf("-1\n"); //오류 발생
    //비어있지 않으면
    else printf("%d\n", s->data[s->top]);
}




int main(void){
    int n;
    char s1[7];
    stack a1;


    scanf("%d", &n);
    fgetc(stdin); //입력 버퍼 비우기
    init(&a1);
    int x;//push x를 위한 변수

    for (int i = 0 ; i < n ; i ++){
        scanf("%s", s1);
        fgetc(stdin);


        if (!strcmp(s1, "push")){ //같으면 0을, 다르면 0이 아닌 값을 반환하기에 !를 통해 반전
            scanf("%d", &x);
            fgetc(stdin);
            push(&a1, x);
        }
        else if (!strcmp(s1, "pop")){
            printf("%d\n",pop(&a1));
        }
        else if (!strcmp(s1, "size")){
            printf("%d\n",(a1.top)+1);
        }
        else if (!strcmp(s1, "empty")){
            printf("%d\n",is_empty(&a1));
        }
        else if (!strcmp(s1, "top")){
            peek(&a1);

        }


    }
}
