#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void IntToAsc(int integer, char *ascii){
    int digit=0;
    int temp=integer;
    while (temp >= 10){ //몇 자리 수인지 확인
        temp/=10;
        digit++;
    }

    ascii[digit+1] = '\0'; // 컴파일러가 NULL을 (void*)0으로 인식하기 때문
    for (int i=digit; i>=0; i--){
        ascii[i] = (integer%10) + '0';
        integer /= 10;
    }
}



int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    char product[10]; // 세 수의 곱을 담은 문자열 / 10^8이면 9자리, null문자까지 10자리
    IntToAsc(a*b*c, product); // 10진법으로 변환

    char digit[10] = {0,}; // 0부터 9까지를 몇 번 사용되었는지 / 처음에는 0으로 초기화
    for (int i=0; i<strlen(product); i++)
        digit[product[i] - '0']++; //0에 해당하는 ASCII값을 빼줘서 숫자화함
    

    for(int i=0; i<10; i++)
        printf("%d ", digit[i]); //0부터 9까지 인덱스를 증가시키며 순회


    return 0;
}