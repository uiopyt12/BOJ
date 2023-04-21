#include <bits/stdc++.h>

int arr[1000000];
int NGE[1000000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);


    std::stack<int> tmxor;
    int n;
    std::cin >> n;

    for (int i=0; i<n; i++)
        std::cin >> arr[i];
    for (int i=n-1; i>=0; i--){
        if (!tmxor.empty()) {
            if (tmxor.top() > arr[i]){
                NGE[i] = tmxor.top();
            }
            else { // tmxor.top() <= arr[i]
                while (!tmxor.empty() && tmxor.top() <= arr[i])
                    tmxor.pop();
                if (tmxor.empty()) NGE[i] = -1;
                else NGE[i] = tmxor.top();
            } 
        }  
    tmxor.push(arr[i]);
    }

    for (int i=0; i<n; i++){
        if (!NGE[i]) std::cout << -1 << ' ';
        else std::cout << NGE[i] << ' '; 
    }
}