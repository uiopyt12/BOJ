#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME 100
#define MAX_WORDS 10000
#define MAX_WORD_SIZE 100
#define TRUE 1
#define FALSE 0


typedef struct
{
    char word[MAX_WORD_SIZE]; //단어를 저장할 변수
    int count;                //단어의 빈도수를 저장할 변수
} element;

typedef struct TreeNode
{
    element key;   //element라는 문자열과 빈도수를 갖는 구조체
    struct TreeNode *left, *right; //트리의 왼쪽과 오른쪽
} TreeNode;

int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
    //왼쪽 값이 크면 -1, 같으면 0, 오른쪽 값이 크면 1 반환
}

//디스크 파일로부터 한 개 단어를 읽어 배열 word에 저장
//성공적으로 읽었으면 TRUE, 그렇지 않으면(파일 끝) FALSE 리턴
int getword(FILE *fd, char *word)
{
    char ch;
    int i;

    do
    {
        ch = getc(fd);
        if (ch == EOF)
            return FALSE;
    } while (!isalpha(ch)); ///첫번째 알파벳 문자가 나올때까지 읽는다.

    i = 0;
    do
    {                     ///단어 1개를 읽는다.
        ch = tolower(ch); ///소문자로 변환
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch)); ///알파벳 문자이면 계속 읽는다.

    word[i] = '\0';

    return TRUE;
}

TreeNode* update_BST(TreeNode **root, element key)
{
    TreeNode *p = *root; //루트부터 트리를 순회하는 포인터
    TreeNode *q = NULL;

    while (p != NULL)
    {
        if (compare(key, p->key) == 0)
        {
            p->key.count++;
            return p;
        }

        q = p;
        if (compare(key, p->key) < 0)
            p = p->left;
        else
            p = p->right;
    }

    //단어를 찾지 못한 상황, 새로운 노드를 만듬
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->key = key;
    newnode->key.count = 1;
    newnode->left = newnode->right = NULL;

    if (q != NULL) //q는 단말노드를 가리킴
    {
        if (compare(key, q->key) < 0) // 왼쪽 값이 작으면
            q->left = newnode; //단말노드의 왼쪽에 삽입
        else
            q->right = newnode; //단말노드의 오른쪽에 삽입
    }
    else //트리가 비어있는 경우
        *root = newnode;
}

void inorder(TreeNode *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%s %d ", p->key.word, p->key.count); //단어와 빈도수를 출력
        inorder(p->right);
    }
}

int get_node_count(TreeNode *node)
{
    int count = 0;
    if (node != NULL) //NULL을 가리키지 않는 동안 내려가며 count를 증가
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    //왼쪽 서브트리와 오른쪽 서브트리의 개수 + 1(자신)
    return count;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(TreeNode *node)
{
    int height = 0;
    if (node != NULL) //NULL을 가리키지 않는 동안 내려가며 높이 측정
        height = 1 + max(get_height(node->left), get_height(node->right));
        //두 값중 큰 값+1이 높이
    return height;
}

int main()
{
    FILE *fd;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;

    char fname[MAX_NAME];  //파일 이름
    char w[MAX_WORD_SIZE]; //읽어들인 단어
    int flag;              //파일 끝이 아닌지 여부

    clock_t start, finish;
    double duration;

    printf("파일 이름: "); ///파일을 불러오는 곳입니다.
    scanf("%s", fname);

    if ( (fd=fopen(fname, "r")) == NULL) //파일을 여는 것에 실패했으면
    {
        fprintf(stderr, "파일을 열수없습니다.\n"); //오류메세지를 출력하고 종료
        return 0;
    }

    start = clock();

    do
    {
        flag = getword(fd, w);
        if (flag == FALSE) //단어가 있다면
            break;
        strcpy(e.word, w);
        update_BST(&root, e);
    } while (1);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    inorder(root); ///LVR로 순회하며 단어와 빈도수 출력

    printf("\n노드 개수 = %d\n", get_node_count(root));
    printf("트리 높이 = %d\n", get_height(root));
    printf("\n%.6f 초입니다.\n", duration);

    return 0;
}