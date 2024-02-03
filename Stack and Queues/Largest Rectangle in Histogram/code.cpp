//Optimize Approach
int Solution::largestRectangleArea(vector<int> &A) {
    stack<int>st;
    int res = 0;
    if(A.size() == 1) return A[0];
    for(int i=0;i<=A.size();i++){
        while(!st.empty() && (i==A.size() || A[st.top()] >= A[i])){
            int height = A[st.top()];
            st.pop();
            int width;
            
            if(st.empty()){
                width = i;
            }
            else{
                width = i - st.top() - 1;
            }
            
            res = max(res, width*height);
        }
        st.push(i);
    }
    return res;
}


//Better Approach
// int largestRectangleArea(vector<int>& arr) {
//     int n = arr.size();
//     int left[n], right[n];
//     int res =0;
//     stack<int> s;

//     for(int i=0;i<n;i++){
//        while(!s.empty() && arr[s.top()] >= arr[i]){
//            s.pop();
//        }
//        if(s.empty()){
//            left[i] = 0;
//        }
//        else{
//            left[i] = s.top() + 1;
//        }
//        s.push(i);
//     }
//     while(!s.empty()){
//         s.pop();
//     }
//     for(int i=n-1;i>=0;i--){
//        while(!s.empty() && arr[s.top()] >= arr[i]){
//            s.pop();
//        }
//        if(s.empty()){
//            right[i] = n-1;
//        }
//        else{
//            right[i] = s.top() - 1;
//        }
//        s.push(i);
//     }

//     for(int i=0; i<n;i++){
//         res = max(res, arr[i] * (right[i] - left[i] + 1));
//     }
//     return res;

// }



