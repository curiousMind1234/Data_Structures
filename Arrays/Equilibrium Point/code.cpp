int equilibriumPoint(long long a[], int n) {
    if(n == 1)return 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    int l_sum = 0;
    
    for(int i=0;i<n;i++){
        int r_sum = sum - a[i];
        if(l_sum == r_sum){
            return i+1;
        }
        
        l_sum += a[i];
        sum -= a[i];
    }
    return -1;
}


Time Complexity: O(n)
Auxiliary Space: O(1)
