bool checkRotatedAndSorted(int arr[], int num){
   int cnt = 0;
   for(int i=0;i<num-1;i++){
       if(arr[i] > arr[i+1]){
           cnt++;
       }
   }
   if(cnt == 1) return true;
   return false; 
}

Time Complexity: O(N).
Auxiliary Space: O(1).
