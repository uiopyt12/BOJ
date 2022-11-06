#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int c;
    scanf("%d", &c);

    int n;
    int temp;
    int sum=0;

    for (int i=0; i<c; i++){
        scanf("%d", &n);

        sum=0;
        int *student = malloc(sizeof(int) * n);
        for (int j=0; j<n; j++){
            scanf("%d", &temp);
            student[j] = temp;
            sum += temp;
        }

        double average = (double)sum / n;
        int count=0;
        for (int j=0; j<n; j++){
            if (student[j] > average){
                count++;
            }
        }
        printf("%.3lf%%\n", round((double)count/n * 100000)/1000);
    }


    return 0;
}