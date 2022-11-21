#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    int **a = (int **)malloc(sizeof(int *) * n);
    int **b = (int **)malloc(sizeof(int *) * n);
    for (int i=0; i<n; i++){
        a[i] = (int *)malloc(sizeof(int) * m);
        for (int j=0; j<m; j++){
            scanf("%d", &(a[i][j]));
        }
    }
    for (int i=0; i<n; i++){
        b[i] = (int *)malloc(sizeof(int) * m);
        for (int j=0; j<m; j++){
            scanf("%d", &(b[i][j]));
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<n; i++){
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);


    return 0;
}