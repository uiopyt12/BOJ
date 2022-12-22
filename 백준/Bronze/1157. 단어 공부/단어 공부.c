#include <stdio.h>
#define conflict 99

int main()
{
    int abc[26] = {0}; //알파벳 문자를 기록할 배열을 초기화(같은 문자가 100만번 나올 수 있음)


    int input;
    while (1)
    {
        input = getc(stdin);
        if (input == '\n')
            break;

        if (input <= 'Z')
            input += ('a'-'A');
        input -= 'a';
        abc[input]++;
    }
    
    int localMax=-1; //localMax는 비교하며 값이 업데이트되는 최대값
    int imax; //imax는 인덱스
    for (int i=0; i<26; i++){
        if (abc[i] > localMax){
            localMax = abc[i];
            imax = i;
        }
        else if (abc[i] == localMax){
            imax = conflict;
        }
    }
    
    if (imax == conflict)
        printf("?");
    else
        printf("%c", (imax+'a')-('a'-'A'));
    

    return 0;
}