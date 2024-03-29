int majorityElement(vector<int>& nums) {
   /** Using Hash map approach **/
    // int n = nums.size();
    // unordered_map<int,int>mp;
    // for(int i=0;i<n;i++)
    // {
    //    mp[nums[i]]++;
    // }
    // int max_count = 0, res =-1;
    // for(auto i :mp)
    // {
    //     if(max_count < i.second)
    //     {
    //         res = i.first;
    //         max_count = i.second;
    //     }
    // }
    // return res;
  
  /** Using Moore's voting algorithm**/
    int candidate = nums[0];
    int count = 0;
    int n= nums.size();

    for(int i=0;i<n;i++){
       //if current element is equal to candidate increment the count else decrement the count
        if(nums[i]==candidate){
            count ++;
        }
        else{
            count--;
        }
        //check if in any case count is 0 then reset candidate to current element
        if(count == 0){
            candidate = nums[i];
            count ++;
        }
    }
   //check if candidate is your ans or not so traverse again
    count = 0;
    for(int i : nums){
        i == candidate;
        count++;
    }
    if(count > n/2){
        return candidate;
    }
    else{
        return -1;
    }
}
