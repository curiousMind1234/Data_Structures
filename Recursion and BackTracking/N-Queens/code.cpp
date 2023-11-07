 bool isSafe(int row, int col, vector<string>& res, int n){
   //Brute force approach
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0){
            if(res[row][col]== 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(res[row][col]== 'Q')  return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(res[row][col]== 'Q')  return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>& res, vector<vector<string>>& ans, int n){
         if(col == n){
             ans.push_back(res);
             return;
         }
         
         for(int row=0; row<n;row++){
             if(isSafe(row, col, res, n)){
                 res[row][col] = 'Q';
                 solve(col + 1, res, ans, n);
                 res[row][col] = '.';
             }
         }
         
         
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n);
        string s(n,'.');
        for(int i=0; i<n;i++){
            res[i] = s;
        }
        solve(0, res, ans, n);
        return ans;

    }

  //Approach using heap

    void solve(int col, vector<string>& res, vector<vector<string>>& ans, vector <int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        if(col == n){
            ans.push_back(res);
            return;
        }
        for(int row =0;row<n;row++){
            if(leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col - row]==0){
                res[row][col] = 'Q';
                leftrow[row] =1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row]=1;
                solve(col+1, res, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                res[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n);
        string s(n,'.');
        for(int i=0; i<n;i++){
            res[i] = s;
        }
        vector <int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0),  lowerDiagonal(2 * n - 1, 0);
      solve(0, res, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
