pair<long, long> findRepeating(long *arr, int n){
    // gives TLE
    // map<int,int>mp;
    // for(int i=0;i<n;i++){
    //     mp[arr[i]]++;
    // }
    
    // for(auto m : mp){
    //     if(m.second > 1){
    //         return make_pair(m.first, m.second);
    //     }
    // }
    
    int freq = -1;
    int elem = -1;
    int low =0, high = n-1; 
    while(low <=high){
        int mid = (low+high)/2;
        if(arr[mid]==arr[mid-1] || arr[mid] == arr[mid+1]){
            elem = arr[mid];
            freq = n - (arr[n-1] - arr[0]); //formula for checking no of 
            //elements is repeated in consecutive manner
        }
        if(arr[mid] >= mid + arr[0]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return make_pair(elem, freq);
}

TC: O(logN)
SC: O(1)
