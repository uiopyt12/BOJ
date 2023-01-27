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
    char word[MAX_WORD_SIZE]; //�ܾ ������ ����
    int count;                //�ܾ��� �󵵼��� ������ ����
} element;

typedef struct TreeNode
{
    element key;   //element��� ���ڿ��� �󵵼��� ���� ����ü
    struct TreeNode *left, *right; //Ʈ���� ���ʰ� ������
} TreeNode;

int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
    //���� ���� ũ�� -1, ������ 0, ������ ���� ũ�� 1 ��ȯ
}

//��ũ ���Ϸκ��� �� �� �ܾ �о� �迭 word�� ����
//���������� �о����� TRUE, �׷��� ������(���� ��) FALSE ����
int getword(FILE *fd, char *word)
{
    char ch;
    int i;

    do
    {
        ch = getc(fd);
        if (ch == EOF)
            return FALSE;
    } while (!isalpha(ch)); ///ù��° ���ĺ� ���ڰ� ���ö����� �д´�.

    i = 0;
    do
    {                     ///�ܾ� 1���� �д´�.
        ch = tolower(ch); ///�ҹ��ڷ� ��ȯ
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch)); ///���ĺ� �����̸� ��� �д´�.

    word[i] = '\0';

    return TRUE;
}

TreeNode* update_BST(TreeNode **root, element key)
{
    TreeNode *p = *root; //��Ʈ���� Ʈ���� ��ȸ�ϴ� ������
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

    //�ܾ ã�� ���� ��Ȳ, ���ο� ��带 ����
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->key = key;
    newnode->key.count = 1;
    newnode->left = newnode->right = NULL;

    if (q != NULL) //q�� �ܸ���带 ����Ŵ
    {
        if (compare(key, q->key) < 0) // ���� ���� ������
            q->left = newnode; //�ܸ������ ���ʿ� ����
        else
            q->right = newnode; //�ܸ������ �����ʿ� ����
    }
    else //Ʈ���� ����ִ� ���
        *root = newnode;
}

void inorder(TreeNode *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%s %d ", p->key.word, p->key.count); //�ܾ�� �󵵼��� ���
        inorder(p->right);
    }
}

int get_node_count(TreeNode *node)
{
    int count = 0;
    if (node != NULL) //NULL�� ����Ű�� �ʴ� ���� �������� count�� ����
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    //���� ����Ʈ���� ������ ����Ʈ���� ���� + 1(�ڽ�)
    return count;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(TreeNode *node)
{
    int height = 0;
    if (node != NULL) //NULL�� ����Ű�� �ʴ� ���� �������� ���� ����
        height = 1 + max(get_height(node->left), get_height(node->right));
        //�� ���� ū ��+1�� ����
    return height;
}

int main()
{
    FILE *fd;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;

    char fname[MAX_NAME];  //���� �̸�
    char w[MAX_WORD_SIZE]; //�о���� �ܾ�
    int flag;              //���� ���� �ƴ��� ����

    clock_t start, finish;
    double duration;

    printf("���� �̸�: "); ///������ �ҷ����� ���Դϴ�.
    scanf("%s", fname);

    if ( (fd=fopen(fname, "r")) == NULL) //������ ���� �Ϳ� ����������
    {
        fprintf(stderr, "������ ���������ϴ�.\n"); //�����޼����� ����ϰ� ����
        return 0;
    }

    start = clock();

    do
    {
        flag = getword(fd, w);
        if (flag == FALSE) //�ܾ �ִٸ�
            break;
        strcpy(e.word, w);
        update_BST(&root, e);
    } while (1);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    inorder(root); ///LVR�� ��ȸ�ϸ� �ܾ�� �󵵼� ���

    printf("\n��� ���� = %d\n", get_node_count(root));
    printf("Ʈ�� ���� = %d\n", get_height(root));
    printf("\n%.6f ���Դϴ�.\n", duration);

    return 0;
}