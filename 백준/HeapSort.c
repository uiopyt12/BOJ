#include <stdio.h>
#define MAX_HEAP_SIZE 1000*1000+1
#define max(a,b) ((a > b) ? a : b)

typedef struct
{
    int heap[MAX_HEAP_SIZE];
    int index;
}Xheap;

Xheap h; //stack area�� ������ �޸� �Ҵ��� ���� ���� data area�� �������� �迭 ����

void init_heap(Xheap* h){
    h->index = 0; //0��° ĭ�� �׻� �������
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upheap(Xheap* h, int data){
    h->index++;
    h->heap[h->index] = data;
    int tempIndex = h->index;
    
    while (tempIndex != 1 && h->heap[tempIndex] > h->heap[tempIndex/2]){ //��Ʈ�� �ƴϰ�, �θ𺸴� ���� ũ��
        swap(&(h->heap[tempIndex]), &(h->heap[tempIndex/2])); //���� �ٲ��ְ�,
        tempIndex /= 2; //�θ��� �ε����� ��´�.
    }

}

int downheap(Xheap* h){
    if (h->index == 0){
        printf("heap is empty\n");
        return 1;
    }

    int root = h->heap[1]; //root ���� �ȿ� ��Ʈ����� ���� �ְ�
    h->heap[1] = h->heap[h->index]; //���� ������ ����� ���� ��Ʈ�� �ű�
    h->index--; //��尡 �ϳ� �پ����� �ε����� �ϳ� ���ҽ�Ŵ

    int tempIndex = 1; //�迭�� ǥ���� ��������Ʈ���� ��ȸ�� �ε���
    int biggerIndex; //���� �ڽİ� ������ �ڽ� �� ū �ڽ��� �ε���
    while (tempIndex <= h->index)
    {
        if (tempIndex*2+1 <= h->index){ //������ �ڽĵ� �����ϰ�, 
            if (h->heap[tempIndex*2] > h->heap[tempIndex*2+1]) //���� �ڽ��� ������ �ڽĺ��� �� ũ��
                biggerIndex = tempIndex*2; //���� �ڽ��� �ε����� ���
            
            else  //������ �ڽ��� �� ũ��
                biggerIndex = tempIndex*2+1; //������ �ڽ��� �ε����� ���
            


            if (h->heap[tempIndex] < h->heap[biggerIndex]){ //��Ʈ���� ũ�ٸ�
                swap(&(h->heap[tempIndex]), &(h->heap[biggerIndex])); //ū�ʰ� ��Ʈ�� ���� �ٲ�
                tempIndex = biggerIndex; //ū���̾��� ���� ����Ŵ
            }
            else //���ų� ������ downheap ����
                break;
        }

        else if (tempIndex*2 ==  h->index){ //���� �ڽĸ� �����ϸ�
                biggerIndex = tempIndex*2; //���� �ڽ��� �ε����� ���
                
                if (h->heap[tempIndex] < h->heap[biggerIndex]){ //��Ʈ���� ũ�ٸ�
                swap(&(h->heap[tempIndex]), &(h->heap[biggerIndex])); //ū�ʰ� ��Ʈ�� ���� �ٲ�
                tempIndex = biggerIndex; //ū���̾��� ���� ����Ŵ
                }
                else //���ų� ������ downheap ����
                    break;
        
        } 

        else if (tempIndex*2 > h->index) //�ڽ��� ���� ���
            break;
    }
    
    
    return root;
}


int main()
{
    init_heap(&h);

    int n;
    scanf("%d", &n);

    int temp;
    for (int i=0; i<n; i++){
        scanf("%d", &temp);
        upheap(&h, temp);
    }

    int arr[n];
    for (int i=n-1; i>=0; i--)
        arr[i] = downheap(&h);
        
    for (int i=0; i<n; i++)
        printf("%d\n", arr[i]);

}