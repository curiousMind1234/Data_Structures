int minimumParentheses(string pattern) {
    int res = 0;
    int balance = 0;
    for(char ch : pattern){
        if(ch == '(') balance++;
        else if(ch == ')'){
            if(balance>0){
                balance--;
            }
            else{
                res++;
            }
        }
    }
    res += balance;
    return res;
}

/*
TC : O(N)
SC : O(1)
*/
