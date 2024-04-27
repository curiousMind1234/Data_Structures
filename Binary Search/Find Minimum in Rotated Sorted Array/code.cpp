//GFG Problem
int minNumber(int arr[], int low, int high){
    int first = low, last = high;
    
    if(arr[high] > arr[low] || low == high){
        return arr[low];
    }
    
    while(first<=last){
        int mid = (first+last)/2;
        if(arr[mid-1] > arr[mid]){
            return arr[mid];
        }
        else if(arr[mid] > arr[mid+1]){
            return arr[mid+1];
        }
        else{
            if(arr[mid] > arr[last]){
                first = mid + 1;
            }
            else{
                last = mid - 1;
            }
        }
    }
    return 0;
}


//LeetCode problem
int findMin(vector<int>& nums) {
        
    // priority_queue<int,vector<int>,greater<int>>pq_min;
    // for(int i=0;i<nums.size();++i)
    // {
    //     pq_min.push(nums[i]);
    // }
    // return pq_min.top();

    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;

    while(low<=high){
        int mid = (low+high)/2;
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);

            low = mid + 1;
        }
        else {
            ans = min(ans, nums[mid]);

            high = mid - 1;
        }
    }
    return ans;
}
