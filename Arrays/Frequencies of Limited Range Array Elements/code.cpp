void frequencyCount(vector<int>& arr,int N, int P) { 
    P++;
    for(int i=0;i<N;i++){
        int idx = arr[i] % P - 1;
        
        if(idx>=0 && idx<N){
            arr[idx] += P;
        }
    }
    for(int i=0;i<N;i++){
        arr[i] /= P;
    }
}

Time complexity: O(N)
Auxiliay space: O(1)
