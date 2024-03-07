vector<int> leaders(int a[], int n){
    vector<int>res;   
    // for(int i=0;i<n;i++){
    //     int j;
    //     for( j=i+1;j<n;j++){
    //         if(a[i] <= a[j]) {
    //             break;
    //         }
    //     }
    //     if(j == n){
    //         res.push_back(a[i]);
    //     }
    // }
    
    int max_from_right = a[n-1];
    res.push_back(max_from_right);
    
    for(int i=n-2;i>=0;i--){
        if(max_from_right <= a[i]){
            max_from_right = a[i];
            res.push_back(max_from_right);
        }
    }
    reverse(res.begin(), res.end());
    return res; 
}

/*
1st Approach
TC : O(n*n)
SC : O(1)

2nd Approach
TC : O(n)
SC : O(1)
*/
