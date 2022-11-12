#include <stdio.h>


int selfnum(int n){
    int temp=n;
    while (n >= 10){
        temp += n%10;
        n /= 10;
    }

    return temp+n;
}


int main()
{
    int dynamicArr[10035] = {0}; 
    //배열을 다룰 때에는 다른 데이터 주소를 침범하지 않도록 주의
    

    
    for (int i=1; i<10001; i++){
        dynamicArr[selfnum(i)] = 1;
    }//selfnum 함수는 10000까지를 입력으로 받지만 9999의 경우 10035를 반환하기 때문에 이에 유의
    
    
    for (int i=1; i<10001; i++){
        if (dynamicArr[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}