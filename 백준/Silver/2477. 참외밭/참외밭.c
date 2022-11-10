#include <stdio.h>


int main()
{
    int perMelon;
    scanf("%d", &perMelon);

    int edge[6];
    int temp;
    for(int i=0; i<6; i++){
        scanf("%d %d", &temp, &edge[i]);
    }

    int max=0; //가장 긴 변을 두개 곱한 넓이
    int sum=0; //붙어있는 두 변끼리의 곱의 합
    for(int i=0; i<5; i++){
        sum += edge[i]*edge[i+1];
        if (max < edge[i]*edge[i+1])
            max = edge[i]*edge[i+1];
    }
    sum += edge[0]*edge[5];
    if (max < edge[0]*edge[5])
            max = edge[0]*edge[5];

    printf("%d", perMelon * (sum-2*max));

    return 0;
}