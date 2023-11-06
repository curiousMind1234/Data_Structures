 void patterns(vector<int>&nums, int idx, vector<int>&res, vector<vector<int>>&result){
    int n = nums.size();
    //base condition
    if(idx == n) {
        result.push_back(res);
        return;
    }
    //pick the element 
    res.push_back(nums[idx]);      
    patterns(nums, idx+1,res,result);

    //remove the element
    res.pop_back();
    patterns(nums, idx+1,res,result);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int> res;    
    patterns(nums, 0, res,result);
    return result;
}
