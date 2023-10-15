int merge(vector<int>& a, int low, int high,int mid){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    int cnt=0;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            cnt += (mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return cnt;
}
int mergeSort(vector<int>& a, int low, int high){
     int cnt = 0;
    if(low>=high) return cnt;
    int mid = (low+high)/2;
    
    cnt+=mergeSort(a, low, mid);
    cnt+=mergeSort(a, mid+1, high);
    cnt+=merge(a, low, high, mid);

    return cnt;
}
int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.

    //Brute Force Approach 
    // int cnt = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         if(i<j && a[i]>a[j]){
    //             cnt++;
    //         }
    //     }
    // }
    // return cnt;

  //Optimal Approach
    return mergeSort(a, 0, n-1);

}
