#include<bits/stdc++.h>
void print(int n, int k, vector<int>& res){
    if(n <= 0) {
        res.push_back(n);
        return;
    }
    res.push_back(n);
    print(n-k, k, res);
    res.push_back(n);
    return;
}
vector<int> printSeries(int n, int k)
{
    vector<int>res;
    print(n,k,res);
    
    return res;
}
