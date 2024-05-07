int maxWater(int arr[], int n) { 
    int maxi = INT_MIN;
    int leftMax = 0;
    
    int rightMax = n-1;
    while(leftMax < rightMax){
        int res = (rightMax-leftMax-1) * min(arr[leftMax], arr[rightMax]);
        maxi = max(maxi, res);
        if(arr[leftMax]< arr[rightMax]){
            leftMax++;
        }
        else{
            rightMax--;
        }
    }
    return maxi;
} 

/*
TC : O(n)
SC : O(1)

*/
