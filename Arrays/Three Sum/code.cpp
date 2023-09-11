vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());  
    vector<vector<int>> res;
    int tar =0;
    for(int i=0; i<=nums.size()-2; i++){ 
        if(i==0  || (nums[i]!=nums[i-1])){
            int j = i+1, k = nums.size()-1;
            int target = tar - nums[i];           
            while(j < k){                 
                if((nums[j]+nums[k]) == target){ 
                    vector<int> list = {nums[i],nums[j],nums[k]}; 
                    res.push_back(list);
                    //to avoid duplicate check
                    while(j<k && (nums[j]==nums[j+1])){j++;}
                    while(j<k && (nums[k]==nums[k-1])){k--;}   
                    j++;
                    k--;      
                }
                else if((nums[j] + nums[k]) < target){
                    j++;
                }
                else{
                    k--;
                }     
            }
        }    
    }
    return res;
}
