long long sum(int *a, int n){
    long long temp=0;
    for (int i=0; i<n; i++){
        temp += a[i];
    }
    return temp;
}