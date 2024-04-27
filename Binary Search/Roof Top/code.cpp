int maxStep(int arr[], int N)
{
    int ans = 0, prev = 0;
    for(int i=1;i<N;i++){
        if(arr[i-1] < arr[i]){
            prev++;
        }
        else{
            prev = 0;
        }
        
        ans = max(ans,prev);
    }
    return ans;
}

TC : O(N)
SC : O(1)
