vector<string> keys={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void combination(int a[], int n, string str, 
       vector<string>& result, int i){
    if(i == n){
        result.push_back(str);
        return;
    }
    int digit = a[i];
    for(int j=0;j<keys[digit].size();j++){
        combination(a, n, str+keys[digit][j], result, i+1);
    }
        
}
vector<string> possibleWords(int a[], int N)
{
    vector<string>result;
    combination(a, N, "", result, 0);
    return result;   
}

Time Complexity: O(4N * N).
Auxiliary Space: O(N).
