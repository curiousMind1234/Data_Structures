vector < int > maxSlidingWindow(vector < int > & nums, int k) {
    vector<int> res;
    deque<int>dq;
    for(int i=0; i< nums.size(); i++){
        //check for out of bound and delete that element
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        //to check for greater element
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1){
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

/*
Time Complexity: O(N)
Space Complexity: O(K)
*/
