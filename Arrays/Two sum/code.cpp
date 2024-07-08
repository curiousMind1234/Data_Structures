 vector<int> twoSum(vector<int>& nums, int target) {
   //vector<int>result;
   map<int, int> mp;
   for( int i=0; i<nums.size();i++)
   {
      if(mp.count(target-nums[i])>0)
          return {mp[target-nums[i]],i};

       mp.insert(make_pair(nums[i],i));
   }
    return {-1,-1};
}
TC : O(n)
SC : O(n)

//When array is sorted in non-decresing order.
vector<int> twoSum(vector<int>& num, int target) {
      int left = 0, right= num.size()-1;
      while(left < right){    
          int sum = num[left] + num[right];    
          if(sum == target){
              return {left+1, right+1};
          }
          else if(sum > target){
              right--;
          }
          else{
              left++;
          }
      }
      return {};
  }

TC : O(n)
SC : O(1)
