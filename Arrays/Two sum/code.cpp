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
