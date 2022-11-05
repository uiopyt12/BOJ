#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d", &n);

    float max=0.0f;
    float sum=0;
    float *transcript = malloc(sizeof(float) * n);
    for (int i=0; i<n; i++){
        scanf("%f", transcript+i);
        if ( max < *(transcript+i) )
            max = *(transcript+i);
        sum+=*(transcript+i);
    }

    printf("%f", sum/n * 100/max);


    return 0;
}