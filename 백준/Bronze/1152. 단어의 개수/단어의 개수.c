#include <stdio.h>


int main()
{
    char input[1000*1000+1];
    scanf("%[^\n]s", input); //%[^\n]s는 \n을 제외한 문자를 \n의 앞까지 받는다는 뜻

    int word = 0;
    int index = 0;
    while (input[index] != '\0'){
        if (input[index] != ' '){
            index++;
            continue;
        }
        word++;             
        index++;
    }
    if (input[0] == ' ')
        word--;
    if (input[index-1] != ' ')
        word++;

    printf("%d", word);


    return 0;
}