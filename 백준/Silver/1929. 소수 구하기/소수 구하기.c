#include <stdio.h>
#include <math.h>
#define SIZE 1000000+1

int prime[SIZE] = {1,1};
void setPrime(void){
    for (int dividend=2; dividend<=SIZE-1; dividend++){
        if (prime[dividend] == 1)
            continue;

        for (int divisor=2; divisor<=sqrt(dividend); divisor++){// sqrt의 오차?
            if (dividend%divisor == 0){
                prime[dividend] = 1; // 대입 연산자와 비교 연산자를 헷갈리지 않게 주의
                break;
            }
        }

        if (prime[dividend] == 0)
            for (int sieve=2*dividend; sieve<=SIZE-1-dividend; sieve+=dividend){
                prime[sieve] = 1; // 변수명을 제대로 사용했는지 유의
            }
    }
}

int main()
{
    setPrime();

    int a,b;
    scanf("%d %d", &a, &b);

    for (int i=a; i<=b; i++){
        if (prime[i] == 0){
            printf("%d\n", i);
        }
    }


   return 0;
}