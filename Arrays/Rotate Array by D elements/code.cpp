
void reverse(int arr[], int low, int high){ 
    while(low<=high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void rotateArr(int arr[], int d, int n){
    d%=n;
    
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

/*
TC : O(n)
SC : O(1)
*/
