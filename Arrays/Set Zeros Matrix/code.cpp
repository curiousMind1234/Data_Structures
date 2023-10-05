/*Brute force Approach*/
void markRow(vector<vector<int>>& matrix, int col, int i){
    for(int j=0;j<col;j++){
        if(matrix[i][j]!=0)
           matrix[i][j] = -1;
    }
}
void markCol(vector<vector<int>>& matrix, int row, int j){
     for(int i=0;i<row;i++){
        if(matrix[i][j]!=0)
           matrix[i][j] = -1;
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                markRow(matrix, col, i);
                markCol(matrix, row, j);
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==-1){
                matrix[i][j] = 0;
            }
        }
    }
}

--------------------------------------------------------------
/*Better Approach*/
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int rArr[200] = {0};
    int cArr[200] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                rArr[i] = 1;
                cArr[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rArr[i]!=0 || cArr[j]!=0){
                matrix[i][j] =0;
            }
        }
    }   
}
-------------------------------------------------------
/*Optimal Approach */
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // int row[200] = {0};  -->matrix[0][..]
    // int col[200] = {0};  -->matrix[..][0]

    int col0 = 1;
    // step 1: Traverse the matrix and
   // mark 1st row & col accordingly:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //mark ith row
                matrix[i][0] = 0;
                //mark jth col
                if(j!=0) {
                   matrix[0][j] = 0;
                }
                else {
                    col0 = 0;
                }                  
            }
        }
    }
    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                   matrix[i][j] = 0;               
                }
            }
            
        }
    }
    //step 3: Finally mark the 1st col & then 1st row:
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        } 
    }
}
