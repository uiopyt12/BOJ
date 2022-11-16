#include <stdio.h>
#include <string.h>


int main()
{
    char s[101];
    scanf("%s", s);

    int answer[26];
    for (int i=0; i<26; i++){
        answer[i] = -1;
    }

    char temp='a';
    for (int i=0; i<strlen(s); i++){
        if (answer[s[i] - 'a'] == -1)
            answer[s[i] - 'a'] = i;
    }

    for (int i=0; i<26; i++){
        printf("%d ", answer[i]);
    }

}