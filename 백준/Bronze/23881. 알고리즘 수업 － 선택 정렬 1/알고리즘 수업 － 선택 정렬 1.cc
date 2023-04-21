#include <bits/stdc++.h>


void swap(int* a, int* b);


int main()
{
    int n, change;
    std::cin >> n >> change;

    int arr[n];
    for (int i=0; i<n; i++){
        std::cin >> arr[i];
    }    


    int cnt=0;
    for (int i=n-1; i>=1; i--){
        int maxI=i;
        for (int j=0; j<=i; j++){
            if (arr[j] > arr[maxI])
                maxI = j;           
        }       
        if (maxI != i){
            swap(&arr[maxI], &arr[i]);
            cnt++;

            if (change == cnt) {
                std::cout << arr[maxI] << ' ' << arr[i];
                break;
            }
                
        }
    }
    
    if (change != cnt) std::cout << -1;


}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}