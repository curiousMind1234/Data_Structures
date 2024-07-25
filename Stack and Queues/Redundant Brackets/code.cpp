#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    int n = s.length();
    bool isreduandant = false;
    for(int i=0;i<n;i++){
        if(s[i]!=')'){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.empty())return true;
            int operatorCount = 0;
            while(st.top() != '('){
               if(st.top() =='+' || st.top()=='-'
                 || st.top()=='*' || st.top()=='/' )
                operatorCount++;

                st.pop();
            }
            st.pop();

            if(operatorCount == 0) return true;
        }
    }
    return false;
}
