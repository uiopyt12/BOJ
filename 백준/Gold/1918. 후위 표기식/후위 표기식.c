#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxStackSize 101

typedef char element;
typedef struct stack{
    element data[MaxStackSize];
    int top;
} stack;

void init(stack *s){//주소값을 복사해와야 값에 접근해 바꿀 수 있음  
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
        exit(1);//오류 발생 
    //가득 차있지 않으면
    else s->data[++(s->top)] = n; //전위 연산자를 통해 top을 하나 증가시킨 후의 인덱스에 n 삽입
}

element pop(stack *s){//top의 원소를 제거하고 그 원소를 반환
    if (is_empty(s)) //비어있으면
        exit(1); //오류 발생
    //비어있지 않으면
    else return s->data[(s->top)--]; //후위 연산자를 통해 data의 top번째 원소를 반환하고 top의 값을 감소
}

element peek(stack *s){//top의 원소를 확인
    if (is_empty(s)){//비어있으면
        exit(1); //오류 발생
    }
    //비어있지 않으면
    return s->data[s->top];
}


int prec(char op){
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    }
    return -1;
}

char *infix_to_postfix(char exp[]){
    int i=0;
    char ch, top_op;
    int len = strlen(exp);
    stack s;

    char *postfix = (char *)malloc(sizeof(char) * (len+2));
    //함수가 종료되고 값을 전달해주기 위해 동적 할당
    sprintf(postfix, ""); //sprintf함수의 형식 때문에 초기화

    init(&s);
    for (int  i=0; i<len ; i++){
        ch = exp[i];
        switch (ch)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            //연산자의 경우
                while (!is_empty(&s) && ((prec(ch)) <= prec(peek(&s))) )
                //스택의 맨 위 연산자와 지금 검사하는 연산자를 비교
                    sprintf(postfix, "%s%c", postfix, pop(&s));
                    //스택의 맨 위 연산자가 현재 검사하는 연산자의 순위보다 더 크거나 같으면 문자열에 붙여줌
                
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);//여는 괄호는 스택에 push
                break;
            case ')':
                top_op = pop(&s); //닫는 괄호를 만나면
                while (top_op != '('){//여는 괄호를 만날 때까지 문자열에 붙여줌
                    sprintf(postfix, "%s%c", postfix, top_op);
                    top_op = pop(&s);
                }
                break;
            default://피연산자의 경우는 그냥 문자열에 붙여줌
                sprintf(postfix, "%s%c", postfix, ch);
                break;
        }
    }
    while(!is_empty(&s))//남아있는 항목들을 꺼내 문자열에 붙여줌
        sprintf(postfix ,"%s%c", postfix, pop(&s));

    return postfix;
}


int main()
{
    char input[100];
    scanf("%s", input);

    
    printf("%s\n", infix_to_postfix(input));

    return 0;
}