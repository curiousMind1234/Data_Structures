int missingNumber(int arr[], int n) 
    { 
        //1st Approach takes O(n) space complexcity and O(n) time complexcity
        bool present[n+1] = {false};
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0 && arr[i] <= n){
                present[arr[i]] = true;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(!present[i]){
                return i;
            }
        }
        
        //2nd Approach takes O(1) space and O(n) time complexcity
        // as we are swapping element to it's correct position 
        // and the element which are not set at it correct position will be our missing number.
      
        for(int i=0;i<n;++i){
            //as 0 based indexing so 3 will be placed at 2 
            //index hence using ar[i] - 1
            while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
               swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        for(int i=0;i<n;++i){
            if(arr[i] != i+1){
                return i+1;
            }
        } 
        return n+1;
    } 
