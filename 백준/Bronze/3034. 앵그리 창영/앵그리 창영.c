#include <stdio.h>


int main()
{
    int n,w,h;
    scanf("%d %d %d", &n, &w, &h);
    int temp;
    for (int i=0; i<n; i++){
        scanf("%d", &temp);
        if (w*w + h*h >= temp*temp)
            printf("DA\n");
        else
            printf("NE\n");
    }
}