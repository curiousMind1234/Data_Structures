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

Time Complexity: O(N*W)
Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.
Space Complexity: O(N*W) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
****************************************************************************************

//Tabulization
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, 0));
	for(int N=0;N<=n;N++){
		dp[0][N] = N * price[0];
	}
	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
			int not_take = 0 + dp[ind-1][N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N){
				take = price[ind] + dp[ind][N-rodLength];
			}  
			dp[ind][N] = max(take,not_take);
		} 
	}
	return dp[n-1][n];
}
Time Complexity: O(N*W)
Reason: There are two nested loops
Space Complexity: O(N*W)
*************************************************************************
	
//Space Optimization using single array
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, 0));
	vector<int>prev(n+1,0);
	for(int N=0;N<=n;N++){
		prev[N] = N * price[0];
	}
	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
          
			int not_take = 0 + prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N){
				take = price[ind] + prev[N-rodLength];
			}  
			prev[N] = max(take,not_take);
		} 
	}
	return prev[n];
}
TC : O(N*N)
SC :O(N)
