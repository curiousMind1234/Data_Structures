bool isValid(string s) {
/**************1st Approach************************/
stack<char>st;
for(int i=0;i<s.length();i++){
    if(st.empty()){
        st.push(s[i]);
    }
    else {
        if((st.top() =='(' && s[i] == ')')
          || (st.top()=='[' && s[i] == ']')
          || (st.top()=='{' && s[i] == '}')){
              st.pop();
          }
          else{
              st.push(s[i]);
          }
    }
}
if(st.empty())return true;
return false;

/********************2nd Approach************************/
int i = -1;
for(auto &ch : s){
    if(ch == '(' ||ch == '{' || ch == '['){
        s[++i] = ch;
    }
    else{
        if(i>=0 && ((s[i] =='(' && ch == ')')
          || (s[i] =='[' && ch == ']')
          || (s[i]=='{' && ch == '}'))){
              i--;
          }
          else {
              return false;
          }
    }
}
return i==-1;
}


/*Algorithm: 

Declare a character stack S.
Now traverse the expression string exp. 
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
After complete traversal, if there is some starting bracket left in stack then “not balanced”

1st Approach :
TC : O(n)
SC : O(n) because of stack

2nd Approach:
TC : O(n)
SC : O(1)

*/
