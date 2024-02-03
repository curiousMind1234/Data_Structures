int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i=0;i<A.size();i++){
        if(A[i]!="+" && A[i]!="-" && A[i]!="*" && A[i]!="/") {
            st.push(stoi(A[i]));
        }
        else if(A[i]=="+" || A[i]!="-" || A[i]!="*" || A[i]!="/") {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(A[i] == "+"){
                st.push(a+b);
            }
            else if(A[i] == "-"){
                st.push(b-a);
            }
            else if(A[i] == "*"){
                st.push(a*b);
            }
            else if(A[i] == "/"){
                st.push(b/a);
            }         
        }
    }
    return st.top();
}


/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
