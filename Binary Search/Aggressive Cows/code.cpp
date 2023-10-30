bool canWePlace(vector<int> &stalls, int mid, int k){
    int cntCow = 1;
    int last = stalls[0];
    for(int i = 1;i<stalls.size();i++){
        if(stalls[i]-last>=mid){
            cntCow++;
            last = stalls[i];
        }
        if(cntCow >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(stalls, mid, k)== true){
            low = mid + 1;
        }
        else{
             high = mid - 1;
        }
    }
    return high;
}
