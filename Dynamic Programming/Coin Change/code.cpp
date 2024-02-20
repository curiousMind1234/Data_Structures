int coinChange(vector<int>& coins, int amount) {
   vector<int> dp(amount+1, amount+1);
   dp[0] = 0;
   for(int it: coins){
       for(int i=it;i<=amount;i++){
           dp[i] = min(dp[i], dp[i - it] +1);
       }
   }
   return dp[amount] == amount + 1 ? -1 : dp[amount];
}

/*
TC : O(n*n)
SC: O(n)
*/
