int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    int left[n], right[n];
    int res =0;
    stack<int> s;

    for(int i=0;i<n;i++){
       while(!s.empty() && arr[s.top()] >= arr[i]){
           s.pop();
       }
       if(s.empty()){
           left[i] = 0;
       }
       else{
           left[i] = s.top() + 1;
       }
       s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i=n-1;i>=0;i--){
       while(!s.empty() && arr[s.top()] >= arr[i]){
           s.pop();
       }
       if(s.empty()){
           right[i] = n-1;
       }
       else{
           right[i] = s.top() - 1;
       }
       s.push(i);
    }

    for(int i=0; i<n;i++){
        res = max(res, arr[i] * (right[i] - left[i] + 1));
    }
    return res;

}
