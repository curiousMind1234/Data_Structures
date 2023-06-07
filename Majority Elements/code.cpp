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
        if(nums[i]==candidate){
            count ++;
        }
        else{
            count--;
        }

        if(count == 0){
            candidate = nums[i];
            count ++;
        }
    }
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
