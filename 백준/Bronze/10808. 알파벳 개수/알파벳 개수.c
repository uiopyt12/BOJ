#include <stdio.h>


int main()
{
    char s[101];
    scanf("%s", s);

    int idx=0;
    char abc[26] = {0};
    while (s[idx] != '\0'){
        abc[(s[idx] - 'a')]++;
        idx++;
    }

    for (int i=0; i<26; i++){
        printf("%d ", abc[i]);
    }
    
    
    return 0;
}