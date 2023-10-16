bool binarySearch(vector<int>& nums, int low, int high, 
   int target){
    if(low>=high) return false;
    while(low<=high){
       int mid = (low+high)/2;

        if(nums[mid] == target){
            return true;
        }
        //Edge case
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        // if exist in left half
        if(nums[low] <= nums[mid]){
            if(nums[low]<= target && target <=nums[mid]){
                high = mid-1;
            }
            else {
                //element not present
                low = mid + 1;
            }
        }
        //if exist in right half
        else{
            if(nums[mid]<= target && target <=nums[high]){
                low = mid;
            }
            else {
                //element not present
                high = mid - 1;
            }
        }
    }
    return false;
}
bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    
    if(nums.size()==1 && nums[0] == target) return true;
    
    return binarySearch(nums, low, high, target);

}
