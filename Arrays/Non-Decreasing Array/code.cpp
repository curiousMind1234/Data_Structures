bool isPossible(int *arr, int n)
{
    int cnt=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            cnt++;
        }
        if(cnt > 1) return false;

        if((i!=1 && arr[i]<arr[i-2])){
            arr[i] = arr[i-1];
        }
    }   
    return true;
}

/*
TC : O(N)
SC :O(1)
*/
