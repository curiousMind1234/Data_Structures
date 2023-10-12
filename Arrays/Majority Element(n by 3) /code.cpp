vector<int> majorityElement(vector<int>& nums) {
   //Using Hashmap
  
    // vector<int>ans;
    // if(nums.size()==1 ){
    //     return nums;
    // }
    // else{
    //     map<int, int>mp;
    //     for(int i=0;i<nums.size();i++){        
    //             mp[nums[i]]++;
    //     }
    
    //     int n = nums.size()/3;
    //     for(auto it :mp){
    //         if(it.second > n){
    //             ans.push_back(it.first);
    //         }
    //     }
    // }    
    // return ans;

    // using Moore's Voting Algorithm
  
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;

    for(int i=0;i<nums.size();i++){
        if(cnt1==0 &&  nums[i]!=el2){
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i]!=el1){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(el1 == nums[i]) cnt1++;
        else if(el2 == nums[i]) cnt2++;
        else {
            cnt1--; cnt2--;
        }  
    }

    cnt1 = 0 , cnt2 = 0;
    for(int i=0 ;i <nums.size();i++){
        if(el1 == nums[i]) cnt1++ ;
        if(el2 == nums[i]) cnt2++;
    }

    int mini = int(nums.size() / 3) + 1;
    if (cnt1 >= mini) ans.push_back(el1);
    if (cnt2 >= mini) ans.push_back(el2);
        
    return ans;
}
