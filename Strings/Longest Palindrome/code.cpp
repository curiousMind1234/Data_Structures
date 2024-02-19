int longestPalindrome(string s) {
    unordered_map<char, int> counts;
    for(auto c : s){
        counts[c]++;
    }
    int res = 0;
    bool odd_found = false;

    for(auto& c: counts){
        if(c.second % 2 == 0) res += c.second;
        else{
            odd_found = true;
            res += c.second - 1;
        }
    }
    if(odd_found){
        res++;
    }
    return res;
}


/*
Time Complexcity : O(n)
Space Complexcity : O(1) using map to count so O(n)

*/
