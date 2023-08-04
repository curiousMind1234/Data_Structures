vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>result ;
    vector<int> res = {};
    checkPermute(nums, res, result);
    return result;
}
void checkPermute(vector<int>& nums, vector<int>& res, vector<vector<int>>& ans){  
    if(res.size()==nums.size()){
        ans.push_back(res);
        return;
    }
    for(int num:nums){
        if(find(res.begin(), res.end(), num) == res.end()){
              res.push_back(num);
              checkPermute(nums,res,ans);
              res.pop_back();
        }    
    }
}
