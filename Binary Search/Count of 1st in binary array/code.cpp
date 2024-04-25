int countOnes(int arr[], int N)
{
   int low = 0, high = N;
   while(low <= high){
       int mid = (low+high)/2;
       if(mid == N) return mid;
       if(arr[mid] == 0){
           high = mid - 1;
       }
       else{
           if(arr[mid+1]==0)
               return mid+1;
           
           else
               low = mid + 1;
       }
   }
   return 0;
}

TC : O(logN)
SC : O(1)
