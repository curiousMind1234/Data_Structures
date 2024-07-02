string reverseStringWordWise(string input)
{
    int n = input.length();
    string res;
    int l=n-1, r=n-1;
    while (l >= 0) {
        if (isspace(input[l])) {
            res += input.substr(l + 1, r - l) + " ";
            r = l - 1;
        }
        l--;
    } 
    // Add the last word (or the only word if there's no space)
    if (r >= 0) {
        res += input.substr(0, r + 1);
    }  
    return res;
}

/*
TC : O(N)
SC : O(1) for result storing string in that case O(N)
*/
