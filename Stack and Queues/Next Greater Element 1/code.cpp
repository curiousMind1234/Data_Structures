 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int n = nums1.size();
    int n1 = nums2.size(); 

   /* First approach */
    // int j;
    // for(int i=0; i<n;i++){
    //     bool found = false;
    //     for(j=0; j<n1;j++){             
    //         if(found && nums2[j] > nums1[i]) {
    //             res.push_back(nums2[j]);
    //             break;
    //         }               
    //         if (nums2[j] == nums1[i]) {
    //             found = true;
    //         }  
    //     }                        
    //     if(j == nums2.size()) res.push_back(-1); 
    // }
    // return res;

   /* Second approach */
   
    stack<int> s;
    unordered_map<int,int> mp;
    
    for(int i=0; i<n1;i++){
       while(!s.empty() && s.top() < nums2[i]){
           mp[s.top()] = nums2[i];
           s.pop();
       }
       s.push(nums2[i]);
    }
    for(int& v : nums1){
        res.push_back(mp.count(v) ? mp[v] : -1);
    }
    return res;
}
