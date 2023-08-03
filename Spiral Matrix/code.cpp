vector<int> spiralOrder(vector<vector<int>>& arr) {
    vector<int> res;
    int m = arr.size();
    int n = arr[0].size();
    int rmin = 0 , rmax = arr.size()-1;
    int cmin = 0 , cmax = arr[0].size()-1;
    int count = 0;
    while(count < m*n){
        //top boundary
        for(int i = cmin ;i<=cmax && count < m*n;i++){
            res.push_back(arr[rmin][i]);
            count ++ ;
        }
        rmin++;
        //right boundary
        for(int i = rmin ;i<=rmax && count < m*n ;i++){
            res.push_back(arr[i][cmax]);
            count ++ ;
        }
        cmax--;

        //bottom boundary
        for(int i = cmax ;i>=cmin && count < m*n; i--){
            res.push_back(arr[rmax][i]);
            count ++ ;
        }
        rmax--;

        //left boundary
        for(int i = rmax ; i >= rmin && count < m*n; i--){
            res.push_back(arr[i][cmin]);
            count ++ ;
        }
        cmin++;
    }
    return res;
}
