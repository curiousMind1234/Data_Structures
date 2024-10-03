#include <bits/stdc++.h> 
void findSub(string str, string res, int idx, vector<string>& ans){

	if(idx >= str.length()){
		if(res.length() > 0){
			ans.push_back(res);
		}
		return;
	}
	//exclude
	findSub(str, res, idx+1, ans);

	//include
	char elem = str[idx];
	res.push_back(elem);
	findSub(str, res, idx+1, ans);
	
}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string output = "";
	findSub(str, output, 0, ans);
	return ans;
	
}
