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
