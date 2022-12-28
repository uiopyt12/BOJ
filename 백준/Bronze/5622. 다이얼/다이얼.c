#include <stdio.h>

char abc[26] = {3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,7,7, 8,8,8,8, 9,9,9, 10,10,10,10};


int main()
{
    char input[16];
    scanf("%s", input);
    
    int index=0, sum=0;
    while (input[index] != '\0'){
        sum += abc[input[index] - 'A'];
        index++;
    }

    printf("%d", sum);


    return 0;
}