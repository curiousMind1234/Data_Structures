//1st approach : iterative
vector<string> combinations(string digits){
	
	if (digits.empty())
      return {};

    vector<string> ans{""};
    const vector<string> digitToLetters{"",    "",    "abc",  "def", "ghi",
                                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (const char d : digits) {
      vector<string> temp;
      for (const string& s : ans){
        for (const char c : digitToLetters[d - '0']){
          temp.push_back(s + c);  
      ans = std::move(temp);
    }

    return ans;
}

// 2nd Approach : Using DFS

const vector<string> digitToLetters{"",    "",    "abc",  "def", "ghi",
                                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(int id, string& digits, string &&path, vector<string>& ans){
    if(id == digits.size()){
      ans.push_back(path);
      return;
    }

    for(const char c : digitToLetters[digits[id]-'0']){
       path.push_back(c);
       dfs(id+1, digits, std::move(path), ans);
       path.pop_back();
    }
}
vector<string> combinations(string digits){
    vector<string>ans;
    dfs(0, digits,"",ans);
    return ans;
}

/*
Time: O(n*4 power n)
Space : O(4 power n)
*/
