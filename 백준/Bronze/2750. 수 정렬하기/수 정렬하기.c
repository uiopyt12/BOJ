#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    

    int index;
    int temp;
    for (int i=0; i<n-1; i++){ // 한 칸씩 뒤로 가며 정렬되지 않은 배열을 최소값부터 정렬
        index = i; // 배열을 순회할 인덱스
        for (int j=i+1; j<n; j++){
            if (arr[index] > arr[j]) 
                index = j;
        }
        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;

    }

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);


    return 0;
}