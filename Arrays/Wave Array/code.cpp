 void convertToWave(int n, vector<int>& arr){
    int i=0,j=1;
    while(i<n-1 && j<n){
        swap(arr[i],arr[j]);
        j+=2;
        i+=2;
    }
}

Time Complexity: O(n).
Auxiliary Space: O(1).
