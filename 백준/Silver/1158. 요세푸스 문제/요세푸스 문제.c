#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5001+1

typedef struct QueueType{
    int Queue[MAX_QUEUE_SIZE];
    int front, rear; // front는 나가는 원소 전을, rear는 들어온 원소를 가리키는 배열 인덱스
}QueueType;

void init_Queue(QueueType *q){
    q->front = q->rear = 0;
}

int is_full(QueueType *q){
    return (q->front == (q->rear+1)%MAX_QUEUE_SIZE);
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

void enqueue(QueueType *q, int data){
    if (! is_full(q)){
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
        q->Queue[q->rear] = data;
    }
}

int dequeue(QueueType *q){
    if (! is_empty(q)){
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
        return q->Queue[q->front];
    }
}


int main()
{
    QueueType *q = malloc(sizeof(QueueType));
    init_Queue(q);

    int n,k;
    scanf("%d %d", &n, &k);

    for (int i=1; i<=n; i++){ // 1부터 n까지 삽입
        enqueue(q, i);
    }

    int temp, ke=1;

    while (! is_empty(q))
    {
        for (int i=0; i<k-1; i++){
            temp = dequeue(q);
            enqueue(q, temp);
        }
        temp = dequeue(q);
        
        if (ke == 1)
            printf("<%d", temp);
        else 
            printf(", %d", temp);

        ke ++;
    }
    printf(">");


    return 0;
}
