int findMax(vector<int>& p){
    int maxi = INT_MIN;
    for(int i=0;i<p.size();i++){
        maxi = max(maxi, p[i]);
    }
    return maxi;
}
double calculateHours(vector<int>& p, int mid){
    double total = 0;
    int n = p.size();
    //find total hours
    for(int i =0;i<n;i++){
        total += ceil((double)p[i]/(double)(mid));
        //totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return total;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = findMax(piles);

    while(low<=high){
        int mid = (low+high)/2;
        double totalH = calculateHours(piles, mid);
        if(totalH <= h){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
