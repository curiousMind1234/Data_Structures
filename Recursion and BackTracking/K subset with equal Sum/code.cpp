Given a vector of integers and an integer k, we are to find if we can divide the array into k non-empty subsets with equal sums. Return true if we can or otherwise, false.

Example 1:
Input: arr = [5,2,1,2,3,4,3], k = 4
Output: true
Explanation: Possible subsets are- [2,3],[2,3],[5],[1,4]

Example 2:
Input: arr = [5,2,1,2,3,4,1], k = 4
Output: false

Precomputation
Before discussing the approaches we should check if it is feasible for the array to be divided into k equal sets or not. For that, compute whether the sum of integers of the array is divisible by k. If not, we cannot divide the array and the size of the array must be equal or greater than k.

For the above input [5,2,1,2,3,4,3], k = 4. Here the length of the array, i.e., n >= k and the sum, i.e., 20 is divisible by 4, so 20%4==0.

Approach #1: Backtracking
Consider a sum of the current subset as currSum, we are at index i, and we want the sum of each subset equal to reqSum = sum(nums[])/k.

We will use a visited[] to keep hold of already used elements.
If currSum + nums[i] > reqSum, we can only skip the ith element and go to the next element.
If !visited[i] and currSum + nums[i] <= resSum, we have two choices, either to include it or not include it in the current subset.
If we include it, we will make visited[i] = true so that the current element cannot be added to any other subset again.
If we find that taking this choice gives us true, we will return true.
Otherwise, we will exclude nums[i] from currSum by making visited[i] = false and go to the next element.
If at any point we find currSum == reqSum, it means we found a subset with the required sum, so call backtrack for k-1 th subset from 0th index.
If your k == 0, it means we found k subsets whose sum is reqSum




#include <bits/stdc++.h> 
bool backtrack(vector<int>& arr, int idx, int reqSum , int currSum,
  vector<bool>& visited, int n, int k){
      if(k==0) return true;

      if(reqSum == currSum){
        return backtrack(arr,0, reqSum, 0, visited, n, k-1);
      }

      if(idx == n) return false;

      if(!visited[idx] && currSum+arr[idx] <= reqSum){
          visited[idx] = true;
          
          if(backtrack(arr,idx+1, reqSum, currSum+arr[idx], visited, n,k)){
              return true;
          }
          visited[idx] = false;
      }

      return backtrack(arr,idx+1, reqSum, currSum, visited, n,k);

  }
bool splitArray(vector<int> &arr, int k) {
    int sum = 0;
    for(int i=0;i<arr.size();i++) sum += arr[i];

    if(sum%k != 0) return false;

    int n = arr.size();
    vector<bool> visited(n, false);
    return backtrack(arr, 0, sum/k,0, visited, n,k);
}



Time complexity: O(k*2^n), for every subset we traverse the whole array and make two recursive calls almost in each traversal.
