void populate(vector<string>& res, string s, int n){
    int idx = s.length();
    if(idx == n){
        res.push_back(s);
        return;
    }

    if(s[idx-1] == '1'){
        populate(res, s+'0', n);
    }

    if(s[idx-1] == '0'){
        populate(res, s+'0', n);
        populate(res, s+'1', n);
    }     
}
vector<string> generateString(int N) {
    if(N<=0) return {};
    vector<string> res;
    string s;
    s.push_back('0');
    populate( res, s, N);

    s[0] = '1';
    populate(res, s, N);
    return res;
}

//TC : O(2^n)
//SC : O(n)
