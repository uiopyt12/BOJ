#include <stdio.h>


long long dynamic[100000];
void preprocess(void){
    dynamic[0] = 0;
    double weight=1;
    for (int i=1; i<100000; i++){
        dynamic[i] = dynamic[i-1] + weight;
        weight += (double)1/2;
    }
}



int main()
{
    preprocess();

    int n;
    scanf("%d", &n);

    int x,y,distance;
    for (int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        distance = y-x;
        for (int j=0; j<100000; j++){
            if (distance <= dynamic[j]){ //같은 상태가 포화 상태
                printf("%d\n", j);
                break;
            }
        }
    }
}