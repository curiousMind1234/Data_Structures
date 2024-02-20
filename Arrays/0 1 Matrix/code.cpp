vector<vector<int>> directions = {{0,1},{-1,0},{0,-1},{1,0}};

void  bfsCheck(vector<vector<int>>& mat, vector<vector<int>>& result, 
       int row,int col,queue<pair<int,int>>& q){

     while(!q.empty()){
         auto a = q.front();
         q.pop();
         int i = a.first;
         int j = a.second;
         for(auto &dir : directions){
             int nrow = i + dir[0];
             int ncol = j + dir[1];

             if(nrow>=0 && nrow < row && ncol>=0 && ncol < col && result[nrow][ncol] == -1){
                 result[nrow][ncol] = result[i][j] + 1;
                 q.push({nrow,ncol});
             }
         }
     }
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> result(row, vector<int>(col, -1));
    queue<pair<int,int>> q;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==0){
                result[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    bfsCheck(mat, result, row,col, q);
   
    return result;
}


/*
Time Complexcity : O(m*n)
Space Complexcity : O(1)
*/
