int minAdjDiff(int arr[], int n){ 
    int res = INT_MAX, diff;
    res = abs(arr[n-1] - arr[0]);
    for(int i=0;i<n;i++){
        res = min(res,abs(arr[i] - arr[i+1]));
    }
    return res;
}

Time Complexity: O(N), as we are using a loop to traverse N times.
Auxiliary Space: O(1), as we are not using any extra space.
