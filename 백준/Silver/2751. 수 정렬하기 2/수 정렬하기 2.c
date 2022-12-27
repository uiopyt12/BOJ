#include <stdio.h>
#define MAX_HEAP_SIZE 1000*1000+1
#define max(a,b) ((a > b) ? a : b)

typedef struct
{
    int heap[MAX_HEAP_SIZE];
    int index;
}Xheap;

Xheap h; //stack area에 과도한 메모리 할당을 막기 위해 data area에 전역으로 배열 선언

void init_heap(Xheap* h){
    h->index = 0; //0번째 칸은 항상 비어있음
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
    
    while (tempIndex != 1 && h->heap[tempIndex] > h->heap[tempIndex/2]){ //루트가 아니고, 부모보다 값이 크면
        swap(&(h->heap[tempIndex]), &(h->heap[tempIndex/2])); //값을 바꿔주고,
        tempIndex /= 2; //부모의 인덱스를 얻는다.
    }

}

int downheap(Xheap* h){
    if (h->index == 0){
        printf("heap is empty\n");
        return 1;
    }

    int root = h->heap[1]; //root 변수 안에 루트노드의 값을 넣고
    h->heap[1] = h->heap[h->index]; //가장 마지막 노드의 값을 루트로 옮김
    h->index--; //노드가 하나 줄었으니 인덱스를 하나 감소시킴

    int tempIndex = 1; //배열로 표현된 완전이진트리를 순회할 인덱스
    int biggerIndex; //왼쪽 자식과 오른쪽 자식 중 큰 자식의 인덱스
    while (tempIndex <= h->index)
    {
        if (tempIndex*2+1 <= h->index){ //오른쪽 자식도 존재하고, 
            if (h->heap[tempIndex*2] > h->heap[tempIndex*2+1]) //왼쪽 자식이 오른쪽 자식보다 더 크면
                biggerIndex = tempIndex*2; //왼쪽 자식의 인덱스를 얻고
            
            else  //오른쪽 자식이 더 크면
                biggerIndex = tempIndex*2+1; //오른쪽 자식의 인덱스를 얻고
            


            if (h->heap[tempIndex] < h->heap[biggerIndex]){ //루트보다 크다면
                swap(&(h->heap[tempIndex]), &(h->heap[biggerIndex])); //큰쪽과 루트의 값을 바꿈
                tempIndex = biggerIndex; //큰쪽이었던 곳을 가리킴
            }
            else //같거나 작으면 downheap 종료
                break;
        }

        else if (tempIndex*2 ==  h->index){ //왼쪽 자식만 존재하면
                biggerIndex = tempIndex*2; //왼쪽 자식의 인덱스를 얻고
                
                if (h->heap[tempIndex] < h->heap[biggerIndex]){ //루트보다 크다면
                swap(&(h->heap[tempIndex]), &(h->heap[biggerIndex])); //큰쪽과 루트의 값을 바꿈
                tempIndex = biggerIndex; //큰쪽이었던 곳을 가리킴
                }
                else //같거나 작으면 downheap 종료
                    break;
        
        } 

        else if (tempIndex*2 > h->index) //자식이 없는 경우
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