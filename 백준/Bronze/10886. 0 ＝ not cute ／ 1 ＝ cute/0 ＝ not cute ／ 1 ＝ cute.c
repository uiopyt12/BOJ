#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);

    int count=0;
    int temp;
    for (int i=0; i<n; i++){
        scanf("%d", &temp);
        if (temp == 1)
            count++;
    }

    if ( (n/2) < count )
        printf("Junhee is cute!");
    else
        printf("Junhee is not cute!");


    return 0;
}