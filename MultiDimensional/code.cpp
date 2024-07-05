int coverageOfMatrix(vector<vector<int>> &mat) {
    int n= mat.size();
    int m= mat[0].size();
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
               
                if(i>0 && mat[i-1][j]==1)sum+=1;
                if(j>0 && mat[i][j-1]==1)sum+=1;
                if(i<n-1 && mat[i+1][j]==1)sum+=1;
                if(j<m-1 && mat[i][j+1]==1)sum+=1;  
            }
        }
    }
    return sum;
}

/*
TC : O(N)
SC : O(1)
*/
