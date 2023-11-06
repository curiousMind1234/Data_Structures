void checkCombination(vector<int>& arr, int idx, vector<int>& res, vector<vector<int>>& result, int target){
    int n = arr.size();
    //base condition
    if(idx == n){
        if(target == 0){
            result.push_back(res);
        }
        return;
    }
    //pick up the element
    if(arr[idx] <= target){
        res.push_back(arr[idx]);
        checkCombination(arr, idx, res, result,target-arr[idx]);
        res.pop_back();       
    }
    checkCombination(arr, idx+1, res, result,target);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>result;
    vector<int>res;
    checkCombination(candidates,0, res, result, target);
    return result;
}
