#include <stdio.h>

int prime[1001];
void setPrime(void){
    int divisor;
    for (int dividend=2; dividend<=1001; dividend++){
        divisor=2;
        while (1){
            if (dividend%divisor == 0)
                break;
            divisor++;
        }
        if (dividend == divisor)
            prime[dividend] = 1;
    }
}

int main()
{
    setPrime();

    int n;
    scanf("%d", &n);

    int temp;
    int count=0;
    for (int i=0; i<n; i++){
        scanf("%d", &temp);
        if (prime[temp] == 1)
            count++;
    }
   printf("%d", count);


   return 0;
}