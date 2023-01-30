#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxStackSize 1000

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

int check_matching(const char* in){ // 상수 문자열의 시작주소를 가리키는 포인터를 매개변수로 받음
    stack s;
    char ch, open_ch;
    int i, n = strlen(in);
    init(&s);


    for (i=0; i<n; i++){
        ch = in[i];
        switch (ch)
        {
        case '(':
            push(&s, ch); //여는 괄호면 스택에 푸쉬함
            break;
        
        case ')':
            if (is_empty(&s)) return 0; //비어있으면 0을 반환

            else {
            open_ch = pop(&s); //스택에 들어있는 것은 여는 괄호뿐임

            if (open_ch == '(' && ch != ')' ) // 맨 위에 있던 괄호와 검사하는 괄호를 비교해 짝이 맞는지 확인
                return 0; //짝이 맞지 않아도 0을 반환

            break; //한 쌍의 괄호 검사 성공, switch문을 빠져나가고 for문의 루프로 돌아감
            }
        }
    } //for문 종료


    if (!is_empty(&s)) return 0; //이 과정을 거쳤는데 남아있으면 오류
    return 1;
}


int eval(char exp[]){
    int op1, op2, value;
    int i=0;
    int len = strlen(exp);
    char ch;
    stack s;

    init(&s);
    for(int i=0; i<len; i++){
        ch = exp[i];
        if //(ch != '+' && ch != '-' && ch != '*' && ch != '/'){ 
            (ch>='0' && ch<='9'){ //피연산자 중 한 자리 문자 형태의 숫자만 다루기 때문
                value = ch -'0';// ASCII코드값을 빼주어 문자값이 아닌 숫자값으로 연산될 수 있도록 함
                push(&s, value);
            }
        else if (ch == ' '){//infix_to_postfix함수에서 초기화할 때 공백을 넣어주었기 때문
            continue;
        }
        else{ //연산자이면
            op2 = pop(&s);//교환법칙이 성립하지 않는 연산도 있음, 2항연산자라 2번 꺼냄
            op1 = pop(&s);//값을 꺼낸 후

            switch (ch)
            {
            case '+': push(&s, op1+op2); break;
            case '-': push(&s, op1-op2); break;
            case '*': push(&s, op1*op2); break;
            case '/': push(&s, op1/op2); break;
            case '%': push(&s, op1%op2); break;
            }//꺼낸 값들을 연산하여 다시 push
        }
    }//for문 종료
    return pop(&s);
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
    sprintf(postfix, " "); //sprintf함수의 형식 때문에 초기화

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

    if (check_matching(input) == 0){
        printf("Error: 괄호가 올바르지 않음.\n");
        exit(1);
    }

    
    printf("POSTFIX:%s\n", infix_to_postfix(input));
    printf("RESULT=%d\n",eval(infix_to_postfix(input)));

    return 0;
}