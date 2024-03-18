int maxEvenOdd(int arr[], int n) 
{ 
    int count = 1, maxi = 1;
    for(int i=1;i<n;i++){
        if((arr[i-1] % 2 == 0 && arr[i] % 2 != 0) ||
         (arr[i-1] % 2 != 0 && arr[i] % 2 == 0)){
             count++;
             if(count > maxi){
                 maxi = count;
             }
         }
         else{
             count = 1;
         }
    }
    return maxi;
} 

Time Complexity: O(N).
Auxiliary Space: O(1).
