vector<vector<int>> directions = {{-1,0}, {0,-1},{1,0},{0,1}};
void DFS(vector<vector<char>>& grid,vector<vector<int>>&visited, 
int i, int j, int n, int m){
    
    visited[i][j] = 1;

    for(auto dir : directions){
        int nrow = i + dir[0];
        int ncol = j + dir[1];

        if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'
               && visited[nrow][ncol]==0){
                   DFS(grid, visited, nrow, ncol,n,m);
               }
    }
}

void BFS(vector<vector<char>>& grid,vector<vector<int>>&visited, 
int i, int j, int n, int m){
    visited[i][j]  = 1;
    queue<pair<int,int>>q;

    q.push({i,j});

    while(!q.empty()){
        pair<int,int> it  =  q.front();
        q.pop();

        int row = it.first;
        int col = it.second;

        for(auto dir : directions){
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'
                   && visited[nrow][ncol]==0){
               visited[nrow][ncol] = 1;
               q.push({nrow,ncol});
           }
       }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visited(n, vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                count++;
                //DFS(grid, visited, i,j, n,m);
                BFS(grid, visited, i,j, n,m);          
            }          
        }
    }
    return count;
}

/*
TC : O(n*m)
SC: O(min(n*m))
*/

*/
