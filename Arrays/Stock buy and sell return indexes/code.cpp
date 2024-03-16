vector<vector<int> > stockBuySell(vector<int> arr, int n){       
    vector<vector<int> >result;
    int sell=0,buy=0;    
    for(int i=0;i<n-1;i++){
       
        if(arr[i+1] > arr[i]) {
            sell++;
        }
        else{
            if(sell > buy) {
                vector<int>res;
                res.push_back(buy);
                res.push_back(sell);
                result.push_back(res);
            }
            buy = i+1;
            sell = i+1;
        }
    }

    //For last combination
    if(sell > buy) {
        vector<int>res;
        res.push_back(buy);
        res.push_back(sell);
        result.push_back(res);
    }  
    return result;
}

Time Complexity: O(N)
Auxiliary Space: O(N)
