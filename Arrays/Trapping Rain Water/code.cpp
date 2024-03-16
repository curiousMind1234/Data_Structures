long long trappingWater(int arr[], int n){
    //1st Approach takes O(n*n) Time complecity O(1) space complexcity
    long long res=0;
    for(int i=1;i<n-1;i++){
        int left_max = arr[i]; 
        for(int j=0;j<i;j++){
             left_max = max(left_max, arr[j]);
        }
        int right_max = arr[i];
        for(int j=i+1;j<n;j++){
             right_max = max(right_max, arr[j]);
        }
        
        res = res + (min(left_max, right_max) - arr[i]);
    }
    return res;


    //2nd Approach takes O(n) Time complecity O(n) space complexcity
    long long res = 0;
    int leftMax[n], rightMax[n];
    
    leftMax[0] = arr[0];
   
    for(int i=1;i<n;i++){
        leftMax[i] = max(arr[i], leftMax[i-1]);
    }
    
    rightMax[n-1] = arr[n-1];
    
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(arr[i], rightMax[i+1]);
    }
    
    for(int i=1;i<n-1;i++){
        int var = min(leftMax[i-1], rightMax[i+1]);
        if(var > arr[i]){
            res+= var - arr[i] ;
        }
    }
    
    return res;
}

//The space complexcity can be reduce by using stacks see other solution in stack directory
