vector<int> pattern(int N){
    vector<int> res;
    int n = N;
    res.push_back(n);
    
    while(n > 0){
        res.push_back(n-5);
        n-=5;
    }
    
    while(n != N){
       res.push_back(n+5);
        n+=5; 
    }
    return res;
}

Time Complexity: O(N)
Auxiliary Space: O(N)
