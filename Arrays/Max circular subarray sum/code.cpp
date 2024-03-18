 int normalSum(int arr[], int num){
    int maxEnding = arr[0];
    int res = arr[0];
    
    for(int i=1;i<num;i++){
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}
int circularSubarraySum(int arr[], int num){
    
    int max_normal = normalSum(arr, num); // kadane algo calculate maxisum subarray sum
    if(max_normal < 0){
        return max_normal;
    }
    
    int arr_sum = 0; 
    for(int i=0;i<num;i++){
        arr_sum += arr[i];
        arr[i] = -arr[i]; // maxCirular = total - minimSubArraySum
        // so to check minisubArraySum we have inverted array
        //so while calculating normalsum it returns minimum subarray sum in array
    }
    
    int max_circular = arr_sum + normalSum(arr, num);
    
    return max(max_normal, max_circular);
}
