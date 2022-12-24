#include <stdio.h>


int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    int eachStack[200000] = {0};
    int eachStackNum;
    for (int i=0; i<m; i++){
        scanf("%d", &eachStackNum); //각 더미에 몇 권이 있는지
        //eachStack[200000]; 다시 덮어쓰니까 더미를 초기화해줄 필요가 없다.

        for (int j=0; j<eachStackNum; j++){ //각 더미의 정보를 읽어서 배열에 저장
            scanf("%d", &eachStack[j]);
        }

        for (int j=0; j<eachStackNum-1; j++){ //정렬되어있는지 검사
            if (eachStack[j] < eachStack[j+1]){ //아래 숫자가 위 숫자보다 작으면
                printf("No");
                return 0;
            }
        }


    }


    printf("Yes");


    return 0;
}