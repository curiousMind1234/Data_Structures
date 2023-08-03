class Solution {
public:
  int search(vector<int>& nums, int target) {
      int minIndex= findMin(nums);
      int ans = binarySearch(nums, 0, minIndex-1,target);
      if(ans == -1){
          ans =  binarySearch(nums, minIndex, nums.size()-1,target);
      }
      return ans;
  }
     
  int binarySearch(vector<int>& nums, int left, int right, int target) {
      while(left <= right){
          int mid = (left + right)/2;
          if (nums[mid] == target){
              return mid;  
          } 
          else if(nums[mid] < target){
              left = mid + 1;
          }
          else {
              right = mid - 1;
          }
      }
      return -1;  
  }

  int findMin(vector<int>& nums) {
      int left = 0, right = nums.size()-1;
      while(left < right){
          int mid = (left + right)/2;  
          if (nums[mid] < nums[right]){
              right = mid;
          }
          else {
              left = mid + 1;  
          } 
      }
      return left;
  }
};
