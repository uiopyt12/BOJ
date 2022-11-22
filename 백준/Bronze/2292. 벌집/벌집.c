#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);

    int ans=1;
    int weight = 6;
    while (n > 1){
        n -= weight;
        ans++;
        weight += 6;
    }

    printf("%d", ans);    

    return 0;
}