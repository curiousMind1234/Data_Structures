void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        for(int i = 0 ; i <N; i++)
          //take transpose
            for(int j=i+1;j<N;j++)
                swap(matrix[i][j],matrix[j][i]);

            //swap the first column with last column  second column with second last column and so on..
            for(int i=0;i<N; i++)
            {
                int low=0, high = N-1; 
                while(low<high)
                {
                    swap(matrix[i][low],matrix[i][high]);
                    low++;
                    high--;
                }
            }
    }
