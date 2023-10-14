int subarraysWithSumK(vector < int > a, int b) {
  //better approach
    // int cnt =0;
    // for(int i=0 ; i<a.size();i++) {
    //     int xor1 = 0;
    //     for(int j = i; j<a.size();j++){
    //         xor1  = xor1 ^ a[j];
            
    //         if(xor1 == b){
    //             cnt++;
    //         }
    //     }    
    // }
    // return cnt;

  //optimize approach
    int xr = 0;
    map<int,int> mp;
    int cnt = 0;
    mp[xr]++;//(0,1)
    
    for(int i=0 ; i<a.size();i++){
        xr = xr ^ a[i];
        
        int x = xr ^ b;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;     
}
