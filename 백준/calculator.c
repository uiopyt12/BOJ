#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxStackSize 1000

typedef char element;
typedef struct stack{
    element data[MaxStackSize];
    int top;
} stack;

void init(stack *s){//�ּҰ��� �����ؿ;� ���� ������ �ٲ� �� ����  
    s->top = -1; //������ �ٴ��� -1
}

int is_empty(stack *s){//����ִ��� Ȯ��
    return (s->top == -1); //top�� -1�̸� 1�� �ƴϸ� 0�� ��ȯ
}

int is_full(stack *s){//���� ���ִ��� Ȯ��
    return (s->top == MaxStackSize-1); // top�� ���� ũ�� -1(�ִ� ���� ũ��)�� ������ 1, �ƴϸ� 0 ��ȯ
} 

void push(stack *s, int n){//���� ������ ���� �� ���Ҹ� ����
    if (is_full(s)) //���� �������� 
        exit(1);//���� �߻� 
    //���� ������ ������
    else s->data[++(s->top)] = n; //���� �����ڸ� ���� top�� �ϳ� ������Ų ���� �ε����� n ����
}

element pop(stack *s){//top�� ���Ҹ� �����ϰ� �� ���Ҹ� ��ȯ
    if (is_empty(s)) //���������
        exit(1); //���� �߻�
    //������� ������
    else return s->data[(s->top)--]; //���� �����ڸ� ���� data�� top��° ���Ҹ� ��ȯ�ϰ� top�� ���� ����
}

element peek(stack *s){//top�� ���Ҹ� Ȯ��
    if (is_empty(s)){//���������
        exit(1); //���� �߻�
    }
    //������� ������
    return s->data[s->top];
}

int check_matching(const char* in){ // ��� ���ڿ��� �����ּҸ� ����Ű�� �����͸� �Ű������� ����
    stack s;
    char ch, open_ch;
    int i, n = strlen(in);
    init(&s);


    for (i=0; i<n; i++){
        ch = in[i];
        switch (ch)
        {
        case '(':
            push(&s, ch); //���� ��ȣ�� ���ÿ� Ǫ����
            break;
        
        case ')':
            if (is_empty(&s)) return 0; //��������� 0�� ��ȯ

            else {
            open_ch = pop(&s); //���ÿ� ����ִ� ���� ���� ��ȣ����

            if (open_ch == '(' && ch != ')' ) // �� ���� �ִ� ��ȣ�� �˻��ϴ� ��ȣ�� ���� ¦�� �´��� Ȯ��
                return 0; //¦�� ���� �ʾƵ� 0�� ��ȯ

            break; //�� ���� ��ȣ �˻� ����, switch���� ���������� for���� ������ ���ư�
            }
        }
    } //for�� ����


    if (!is_empty(&s)) return 0; //�� ������ ���ƴµ� ���������� ����
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
            (ch>='0' && ch<='9'){ //�ǿ����� �� �� �ڸ� ���� ������ ���ڸ� �ٷ�� ����
                value = ch -'0';// ASCII�ڵ尪�� ���־� ���ڰ��� �ƴ� ���ڰ����� ����� �� �ֵ��� ��
                push(&s, value);
            }
        else if (ch == ' '){//infix_to_postfix�Լ����� �ʱ�ȭ�� �� ������ �־��־��� ����
            continue;
        }
        else{ //�������̸�
            op2 = pop(&s);//��ȯ��Ģ�� �������� �ʴ� ���굵 ����, 2�׿����ڶ� 2�� ����
            op1 = pop(&s);//���� ���� ��

            switch (ch)
            {
            case '+': push(&s, op1+op2); break;
            case '-': push(&s, op1-op2); break;
            case '*': push(&s, op1*op2); break;
            case '/': push(&s, op1/op2); break;
            case '%': push(&s, op1%op2); break;
            }//���� ������ �����Ͽ� �ٽ� push
        }
    }//for�� ����
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
    //�Լ��� ����ǰ� ���� �������ֱ� ���� ���� �Ҵ�
    sprintf(postfix, " "); //sprintf�Լ��� ���� ������ �ʱ�ȭ

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
            //�������� ���
                while (!is_empty(&s) && ((prec(ch)) <= prec(peek(&s))) )
                //������ �� �� �����ڿ� ���� �˻��ϴ� �����ڸ� ��
                    sprintf(postfix, "%s%c", postfix, pop(&s));
                    //������ �� �� �����ڰ� ���� �˻��ϴ� �������� �������� �� ũ�ų� ������ ���ڿ��� �ٿ���
                
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);//���� ��ȣ�� ���ÿ� push
                break;
            case ')':
                top_op = pop(&s); //�ݴ� ��ȣ�� ������
                while (top_op != '('){//���� ��ȣ�� ���� ������ ���ڿ��� �ٿ���
                    sprintf(postfix, "%s%c", postfix, top_op);
                    top_op = pop(&s);
                }
                break;
            default://�ǿ������� ���� �׳� ���ڿ��� �ٿ���
                sprintf(postfix, "%s%c", postfix, ch);
                break;
        }
    }
    while(!is_empty(&s))//�����ִ� �׸���� ���� ���ڿ��� �ٿ���
        sprintf(postfix ,"%s%c", postfix, pop(&s));

    return postfix;
}

int main()
{
    char input[100];
    scanf("%s", input);

    if (check_matching(input) == 0){
        printf("Error: ��ȣ�� �ùٸ��� ����.\n");
        exit(1);
    }

    
    printf("POSTFIX:%s\n", infix_to_postfix(input));
    printf("RESULT=%d\n",eval(infix_to_postfix(input)));

    return 0;
}