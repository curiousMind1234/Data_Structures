bool canConstruct(string ransomNote, string magazine) {     
    vector<int> count(26);
    for(auto c : magazine){
        ++count[c - 'a'];
    }
    for(auto c : ransomNote){
        if(count[c - 'a'] == 0){
            return false;
        }
        --count[c - 'a'];
    }
    return true;
}

/*
Time Complexcity: O(ransomNote + magazine)
Space Complexcity : O(26) => O(1)
*/
