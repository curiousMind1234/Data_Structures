int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, len =0 ;
    int n = s.length();
    vector<int> mp(256, -1);

    while(right < n){
        if(mp[s[right]] != -1){
            left = max(mp[s[right]]+1, left);
        }
        mp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

/*
Time Complexcity : O(N)
Space Complexcity : O(N)
*/
