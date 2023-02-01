// �迭�� ����� �ܾ� ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>

#define MAX_FNAME 100
#define MAX_WORDS 10000
#define MAX_WORD_SIZE 100
#define TRUE 1
#define FALSE 0

// ������ ����
typedef struct
{
    char word[MAX_WORD_SIZE]; // Ű�ʵ�
    int count;
} element;

// ��ũ ���Ϸκ��� �� �� �ܾ �д´�.
int getword(FILE *fd, char *word)
{
    char ch;
    int i;

    do
    {
        ch = getc(fd);
        if (ch == EOF)
            return FALSE;
    } while (!isalpha(ch)); // ù��° ���ĺ� ���ڰ� ���ö����� �д´�.
    i = 0;
    do
    {                     // �ܾ� 1���� �д´�.
        ch = tolower(ch); // �ҹ��ڷ� ��ȯ
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch)); // ���ĺ� �����̸� ��� �д´�.
    word[i] = '\0';
    return TRUE;
}

// wlist �迭�� �ܾ� �߰� �Ǵ� �̹� �ִ� ���    �� ����
int update_wlist(int *max_words, element wlist[], char *word)

{
    int i;

    // word�� wlist�� ��� �ִ��� ã�Ƽ� count ����
    for (i = 0; i < *max_words; i++)
    {
        if (strcmp(wlist[i].word, word) == 0)
        {
            wlist[i].count++;
            return wlist[i].count;
        }
    }
    if (i >= MAX_WORDS)
    {
        fprintf(stderr, "Error: too many words ...\n");
        exit(1);
    }
    // �� word�� ��� wlist�� �߰�
    strcpy(wlist[i].word, word);
    wlist[i].count = 1;
    (*max_words)++;
    return wlist[i].count;
}

// �迭 ����Ʈ�� ����ϴ� �ܾ� �� ���
void main()
{
    FILE *fd;
    element wordlist[MAX_WORDS];
    char fname[MAX_FNAME];
    char w[MAX_WORD_SIZE];
    int flag;
    int wnum, cnt;
    int i;
    clock_t start, finish;
    double duration;

    printf("���� �̸�: ");
    scanf("%s", fname);
    if ((fd = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr, "������ ���������ϴ�.\n");
        return;
    }
    wnum = 0;
    cnt = 0;
    start = clock(); // �ð� ���� ����
    do
    {
        flag = getword(fd, w); // �ܾ� 1�� �б�
        if (flag == FALSE)
            break;
        cnt = update_wlist(&wnum, wordlist, w); // wordlist update
                                                //        printf(" %s(%d)", w, cnt);
    } while (1);
    finish = clock(); // �ð� ���� ����
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    for (i = 0; i < wnum; i++)
    {
        printf("%s %d ", wordlist[i].word, wordlist[i].count);
    }
    printf("\n%.6f ���Դϴ�.\n", duration);
}
