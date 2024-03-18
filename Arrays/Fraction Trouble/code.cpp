Consider the set of irreducible fractions A = {n/d | n≤d and d ≤ 10000 and gcd(n,d) = 1}.You are given a member of this set and your task is to find the largest fraction in this set less than the given fraction.
Note : this is a set and so all the members are unique.
// p/q >= num/deno
// p*deno >= q*num
// p = (num * q)/deno
vector<int>LargestFraction(int n, int d){
    int num = 0, den = 1;
    vector<int> res;
    
    int max_d = 10000;
    for(int q=max_d;q>=2;q--){
        int p = (n * q - 1)/d;
       
        if(p * den >= q * num){
            num = p;
            den = q;
        }
    }
    int g = __gcd(num, den);
    res.push_back(num/g);
    res.push_back(den/g);
    
    return res;
}

Time Complexity: O(K) where K <= 10000
Space Complexity: O(1) as used vector for storing output so it it not considered.
