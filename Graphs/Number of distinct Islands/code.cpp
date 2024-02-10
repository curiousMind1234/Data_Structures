private:
    void DFS(int row, int col,vector<vector<int>> &vis,vector<vector<int>>& grid,
    vector<pair<int,int>>&temp, int row0, int col0){
        vis[row][col] = 1;
        temp.push_back({row-row0, col-col0});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dirrow[] = {0,-1,0,+1};
        int dircol[] = {-1,0,+1,0};
        
        for(int i=0;i<4;i++){
            int nrow = row + dirrow[i];
            int ncol = col + dircol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m &&
             !vis[nrow][ncol] && grid[nrow][ncol]==1){
                 DFS(nrow, ncol,vis,grid,temp,row0,col0);
             }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>temp;
                    DFS(i,j,vis,grid,temp,i,j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }

/*   
    Time Complexity = O(N * M)
    Space Complexity = O(N * M)
    
    where N and M are rows and columns 
    of the input array respectively
*/
