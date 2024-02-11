https://www.geeksforgeeks.org/problems/word-break1352/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

private:
    int solve(int ind, string s, vector<int>&memo){
        if(ind >= n) return 1;
        
        if(memo[ind]!= -1) return memo[ind];
        if(mp.find(s)!=mp.end()){
            return memo[ind] = 1;
        }
        for(int l=1;l<=n;l++){
            string temp = s.substr(ind, l);
            if(mp.find(temp)!=mp.end() && solve(ind+l, s, memo)){
                 return memo[ind] = 1;
            }
            
        }
        return 0;
    }
public:
    unordered_set<string>mp;
    int n = 0;
    int wordBreak(string A, vector<string> &B) {
         n = A.size();
        for(auto &it : B){
            mp.insert(it);
        }
        
        vector<int>memo(n+1, -1);
        return solve(0, A, memo);
        
    }
};

Time Complexity: O(N^3), where N is the length of the string S
Space Complexity: O(N), since dp array is used.


https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
    unordered_set<string>mp;
    for(auto &it : B){
        mp.insert(it);
    }    
    vector<int>dp(n+1, 0);
    
    for(int l=1;l<=n;l++){
        dp[l] = dp[l-1] + 1;
        for(int k=max(1, l-19);k<=l;k++){
            string temp = A.substr(k-1,l-k+1);
            if(mp.find(temp)!=mp.end()){
                dp[l] = min(dp[l], dp[k-1]);
            }
        } 
    }
    return (dp[n] == 0);
        
}
