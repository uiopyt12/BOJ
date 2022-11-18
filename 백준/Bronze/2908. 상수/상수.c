#include <stdio.h>


int main()
{
    char a[4];
    char b[4];
    scanf("%s %s", a, b);

    int ra,rb;
    ra=(a[0]-'0')+10*(a[1]-'0')+100*(a[2]-'0');
    rb=(b[0]-'0')+10*(b[1]-'0')+100*(b[2]-'0');
    
    printf("%d", (ra>rb)?ra:rb);

    
    return 0;
}