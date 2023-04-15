#include <bits/stdc++.h>

void swap(int* a, int* b);

int main()
{
    int n, change;
    std::cin >> n >> change;

    int A[n];
    for (int i=0; i<n; i++)
        std::cin >> A[i];


    int cnt=0;
    int flag=1;
    for (int i=n-1; i>=1; i--){
        for (int j=0; j<i; j++){
            if (A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                cnt++;
                if (cnt == change){
                    std::cout << A[j] << ' ' << A[j+1];
                    flag=0;
                }

            }
                
        }

    }

    if (flag)
        std::cout << -1;




}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}