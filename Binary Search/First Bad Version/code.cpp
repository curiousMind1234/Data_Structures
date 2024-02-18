int firstBadVersion(int n) {
    long long int first = 1, last = n, pos = 1;
    while(first<=last){
        int mid = (first + last)/2;

        if(isBadVersion(mid)){
            pos = mid;
            last = mid-1;
        }
        else{
            first = mid+1;
        }
    }
    return pos;
}
