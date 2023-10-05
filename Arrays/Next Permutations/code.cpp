void nextPermutation(vector<int>& nums) {
    // 1st approach use C++ STL
    //next_permutation(nums.begin(), nums.end());

    //2nd Approach
    int idx = -1;
    int n = nums.size();

    for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
           idx = i;
           break;
        }
    }
    if(idx == -1){ 
        //no break index we know we came at the last permuatation
        // so just reverse
        reverse(nums.begin(), nums.end()); 
        return;
    }

    //find the most nearest greater number of idx
    for(int i=n-1;i>idx;i--){
        if(nums[idx] < nums[i]){
            swap(nums[idx], nums[i]);
            break;
        }
    }

    reverse(nums.begin()+ idx+1, nums.end());
}
