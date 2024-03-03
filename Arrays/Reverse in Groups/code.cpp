void reverseInGroups(vector<long long>& arr, int n, int k){
    for(int i=0;i<n;i+=k) {
        long long low = i;
        long long high = min(i+k-1, n-1);
        while(low <= high){
            long long temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
         
            low++; high--;
        }
    }
}

/*
Time Complexcity : O((n/k) * (k/2)) = O(n/2)
Space Complexcity : O(1)
*/
