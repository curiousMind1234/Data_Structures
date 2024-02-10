https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int solve(int ind, int N, vector<int> &price, vector<vector<int>>&dp){
	if(ind == 0){
		return N * price[0];
	}
	if(dp[ind][N]!=-1)return dp[ind][N];
	int not_take = 0 + solve(ind-1, N, price,dp);
	int take = INT_MIN;
	int rodLength = ind+1;
	if(rodLength <= N){
		take = price[ind] + solve(ind, N-rodLength, price, dp);
	}
	return dp[ind][N] = max(take,not_take);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return solve(n-1,n, price,dp);

}
