void backTrack(int n, int id, int k, vector<vector<int>>& result, vector<int>res){
    if(k == res.size()){
        result.push_back(res);
        return;
    }

    for(int i = id;i<=n;i++){
        res.push_back(i);
        backTrack(n,i+1,k,result,res);
        res.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    
    vector<vector<int>> result;
    if (k <= 0 || n <= 0) return result;

    vector<int>res;    
    backTrack(n,1,k,result,res);
    return result;
}


/*
Time Complexity:  O((nCk)*k), where nCk is all possible subsets and k to copy subsets into ans vector.
Auxiliary Space: O((nCk)*k), to store all n C k subset in the ans vector of size k.

*/
*/
