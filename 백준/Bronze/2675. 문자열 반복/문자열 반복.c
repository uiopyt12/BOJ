#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int r;
    char s[21];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &r, s);
        for (int j=0; j<strlen(s); j++){
                for (int k=0; k<r; k++){
                    printf("%c", s[j]);
                }
        }
        printf("\n");
    }
}