#include <bits/stdc++.h>
int countStudent(vector<int>& arr, int pages){
    int stud = 1, pageStudent = 0;
    for(int i=0;i<arr.size();i++){
        if(pageStudent + arr[i] <= pages){
            pageStudent += arr[i];
        }
        else{
            stud++;
            pageStudent = arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid = (low + high)/2;
        int student =  countStudent(arr, mid);
        if(student > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
