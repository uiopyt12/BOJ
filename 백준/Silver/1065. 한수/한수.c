#include <stdio.h>

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

int is_hansu(int n){
    char temp[5];
    IntToAsc(n, temp);

    if (n < 100)
        return 1;
    
    if (temp[1] - temp[0] == temp[2] - temp[1]) //세자리수만 다룸, 1000은 한수가 아님
        return 1;
    else 
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count=0;
    for (int i=1; i<n+1; i++){
        if (is_hansu(i) == 1)
            count++;
    }
    printf("%d", count);


    return 0;
}