void arrange(long long arr[], int n) {
   for(int i=0;i<n;i++){
       arr[i] += (arr[arr[i]] % n) * n;
   }
   for(int i=0;i<n;i++){
       arr[i] =  arr[i]/n ;
   } 
}

/*
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation: 
arr[arr[0]] = arr[4] = 3
arr[arr[1]] = arr[0] = 4
arr[arr[2]] = arr[2] = 2
arr[arr[3]] = arr[1] = 0
arr[arr[4]] = arr[3] = 1
and so on
So, arrT becomes {3, 4, 2, 0, 1}
  
15 20 10 0 5  --> (arr[arr[i]] % n) * n;
3 4 2 0 1   ---> arr[i]/n

Time Complexity: O(N)
Auxiliary Space: O(1)

*/
