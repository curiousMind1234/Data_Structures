bool helper(int n, int k){
    if(n % k == 0) return false;
    
    if(n < k) return true;
    
    return(helper((n-(n/k)),k+1));
}
bool isLucky(int n) {
    return helper(n,2); 
}

TC : O(logn)
SC : O(logn)
------------------------------------------------------------------------
 bool isLucky(int n) {
    for(int i=2;i<=n;i++){
        if(n%i==0){
            return false;
        }
        n=n-(n/i);
    }
    return true;
}

TC : O(n)
SC : O(1)
