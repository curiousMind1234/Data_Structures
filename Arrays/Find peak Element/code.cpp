int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n==1)return 0; //has only one element
    if(nums[0] > nums[1]) return 0; //1st element is peak
    if(nums[n-1]> nums[n-2]) return n-1; //last element is peak

    int low = 1, high = n - 2;
    while(low<=high){
        int mid = (low+high)/2;

         //mid is peak element
        if(nums[mid-1]< nums[mid] && nums[mid] > nums[mid+1]){
            return mid;
        }
        // If we are in left half
        if(nums[mid]>=nums[mid-1]) low = mid + 1;
        
        //If we are in right half
        else high = mid - 1;
    }
    //default case
    return -1;
}
