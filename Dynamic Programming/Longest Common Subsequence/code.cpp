//Using memoization

int solve(int n, int m, string &s1, string &s2,vector<vector<int>>& memo){
    if(n<0 || m<0){
    return 0;
  }
  if(memo[n][m] != -1) return memo[n][m];
  
  if(s1[n] == s2[m]){
     memo[n][m] = 1 + solve(n-1,m-1, s1, s2,memo);
  }
  else{
     memo[n][m] = max(solve(n,m-1, s1,s2,memo),
          solve(n-1,m,s1,s2,memo));
  }
  return memo[n][m];
}

int lcs(int n, int m, string s1, string s2)
{
    vector<vector<int>> memo(n+1, vector<int>(m+1,-1));
    return solve(n-1,m-1, s1,s2,memo);
}

/*
TC: O(nm)
SC: O(nm)
*/
