vector<int> twoRepeated (int arr[], int n) {
    vector<int> result(n+2, 0);
    vector<int>res;
    
    for(int i=0;i<n+2;i++){
        if(result[arr[i]]==0){
            result[arr[i]]++;
        }
        else if(result[arr[i]] == 1){
            result[arr[i]]++;
            res.push_back(arr[i]);
        }
    }
    return res;
}

/*
TC : O(n)
SC : O(1)
