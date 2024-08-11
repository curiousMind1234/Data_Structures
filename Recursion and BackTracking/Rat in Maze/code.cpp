//1st Approach

void findAllHelper(vector<vector<int>>&vis,
      vector<vector<bool>>&arr, vector<string>& path, 
       int row, int col, string moves, int n){
    if(row == n-1 && col == n-1){
        path.push_back(moves);
        return;
    }

    //downward
    if(row+1 < n && !vis[row+1][col] && arr[row+1][col] == 1){
        vis[row][col] = 1;
        findAllHelper(vis, arr, path,row+1, col, moves+'D', n);
        vis[row][col] = 0;
    }

    //left
    if(col-1 >=0 && !vis[row][col-1] && arr[row][col-1] == 1){
        vis[row][col] = 1;
        findAllHelper(vis, arr, path,row, col-1, moves+'L', n);
        vis[row][col] = 0;
    }
    //right
    if(col+1 < n && !vis[row][col+1] && arr[row][col+1] == 1){
        vis[row][col] = 1;
        findAllHelper(vis, arr, path,row, col+1, moves+'R', n);
        vis[row][col] = 0;
    }
    //upward
    if(row-1 >=0 && !vis[row-1][col] && arr[row-1][col] == 1){
        vis[row][col] = 1;
        findAllHelper(vis, arr, path,row-1, col, moves+'U', n);
        vis[row][col] = 0;
    }
}
vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    vector<string> path;
    int n = arr.size();

    vector<vector<int>> vis(n,vector<int>(n,0));
    if(arr[0][0] == 1)findAllHelper(vis, arr, path, 0,0,"",n);

    return path;

}

//rectify first helper function 

vector<int>dr = {1, 0, 0, -1};
vector<int>dc = {0, -1, 1, 0};
void findAllHelper(vector<vector<int>>&vis,
      vector<vector<bool>>&arr, vector<string>& path, 
       int row, int col, string moves, int n){
    if(row == n-1 && col == n-1){
        path.push_back(moves);
        return;
    }

    string str = "DLRU";
    for(int i=0;i<4;i++){
        int nexti = row + dr[i];
        int nextj = col + dc[i];

        if(nexti >= 0 && nextj >= 0 &&
         nexti < n && nextj < n &&
          !vis[nexti][nextj] && arr[nexti][nextj] == 1){
            vis[row][col] = 1;
            findAllHelper(vis, arr, path,nexti, nextj, moves+str[i], n);
            vis[row][col] = 0;
        }
    }
}

/*
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
*/
