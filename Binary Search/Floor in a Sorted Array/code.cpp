int findFloor(vector<long long> v, long long n, long long x){
    long long low =0, high = n-1, res = -1;
    while(low<=high){
        long long mid = (low+high)/2;
        if(v[mid] <= x){
            res = max(mid, res);
            low = mid + 1;
        }
        else if(v[mid] > x){
            high = mid - 1;
        }
    }
    return res;   
}

TC: O(logn)
SC: O(1)
