https://www.interviewbit.com/problems/add-one-to-number/
/*
Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &a) {
    int n =  a.size();
    
    int num = a[n-1] + 1;
    int carry = num/10; //we need to store if num is > 9
    
    vector<int> res;
    res.push_back(num  % 10);
    for(int i=n-2;i>=0;i--){
        num = a[i]+ carry;
        carry = num/10;
        res.push_back(num  % 10);   
    }
    int i = n-1;
    // carry is 1 we need to add it in front of array
    if(carry!=0){
        res.push_back(carry);
        i = n;
    }
    //removing leading 0's
    while(res[i]==0) {
        res.pop_back();
        i--;
    }
    // got ans in reverse order
    reverse(res.begin(),res.end());
    return res; 
}

TC : O(nlogn)
SC : O(1)
