vector<int> asteroidCollision(vector<int>& arr) {
    int n = arr.size();
    vector<int> res;
    stack<int> s;
    for(int i=0; i<n;i++){
       if(arr[i] > 0 || s.empty()){
            s.push(arr[i]);
       }
       else{
           while(!s.empty() && abs(arr[i]) > s.top() && s.top() > 0)
           s.pop();
           if(s.empty() || s.top() < 0) s.push(arr[i]);

           if(!s.empty() && abs(arr[i]) == s.top()) s.pop();             
       }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
