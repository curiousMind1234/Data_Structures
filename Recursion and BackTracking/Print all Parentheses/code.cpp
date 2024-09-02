void solve(int open, int close, int n, string s){
    if(open == n && close == n){
        cout << s << endl;
        return;
    }

    if(open < n){
        solve(open+1, close, n, s+"{");
    }

    if(open > close){
        solve(open, close+1, n, s+"}");
    }
}
void printParantheses(int n) {
    solve(0,0,n,"");
}

// Time complexity: O(2^n), as there are 2^n possible combinations of ‘(‘ and ‘)’ parentheses.
// Auxiliary space: O(n), as n characters are stored in the str array.
