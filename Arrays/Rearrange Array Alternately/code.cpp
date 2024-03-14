How does expression “arr[i] += arr[max_index] % max_element * max_element” work ? 
The purpose of this expression is to store two elements at index arr[i]. arr[max_index] is stored as multiplier and “arr[i]” is stored as remainder. For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. With 91, we can get original element as 91%10 and new element as 91/10.
Below implementation of the above idea:

n = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.

void rearrange(long long *arr, int n) 
{ 
  int max_idx = n-1, min_idx = 0;
  
  int max_elem = arr[n-1] + 1;
  
  for(int i=0;i<n;i++){
      // at even index : we have to put maximum element
      if(i % 2 == 0){
          arr[i] += (arr[max_idx] % max_elem) * max_elem;
          max_idx--;
      }
      // at odd index : we have to put minimum element
      else{
          arr[i] += (arr[min_idx] % max_elem) * max_elem;
          min_idx++;
      }
  }
  
  for(int i=0;i<n;i++){
     arr[i] = arr[i]/max_elem;
  }
}

Time Complexity: O(N).
Auxiliary Space: O(1).
