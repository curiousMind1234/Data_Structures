bool solve(vector<vector<char>>& board, string word, int row, int col, int n, int m, int index){
    if(index == word.length()) return true;

    if(row < 0 || col <0  || row == n || col == m || board[row][col]!=word[index] || board[row][col] == '.')
    return false;

    char c = board[row][col];
    board[row][col] = '.';

    bool top = solve(board, word, row-1, col, n,m, index+1);
    bool right = solve(board, word, row, col+1, n,m, index+1);
    bool bottom = solve(board, word, row+1, col, n,m, index+1);
    bool left = solve(board, word, row, col-1, n,m, index+1);

    board[row][col] = c;

    return top || right || bottom || left;
    
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    int index =0;
    for(int i =0; i< n;i++){
        for(int j=0; j<m ;j++){
            if(board[i][j] == word[index]){
                if(solve(board, word, i, j, n,m, index))
                   return true;
            }
        }
    }
    return false;
}
