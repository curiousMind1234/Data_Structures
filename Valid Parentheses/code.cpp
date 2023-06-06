bool isValid(string s) {
        stack<char> st;
        char x;
        for(int i=0;i< s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
                continue;
            }
            // IF current character is not opening
            // bracket, then it must be closing. So stack
            // cannot be empty at this point.
            if(st.empty())return false;
            switch(s[i])
            {
                case ')':
                    x = st.top();
                    st.pop();
                    if(x =='[' || x =='{')
                        return false;
                    break;
                
                case ']':
                    x = st.top();
                    st.pop();
                    if(x =='(' || x =='{')
                        return false;
                    break;
                    
                case '}':
                    x = st.top();
                    st.pop();
                    if(x =='(' || x =='[')
                        return false;
                    break;     
            }       
        }
        return st.empty();
    }
};

/*Algorithm: 

Declare a character stack S.
Now traverse the expression string exp. 
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
After complete traversal, if there is some starting bracket left in stack then “not balanced”

*/
