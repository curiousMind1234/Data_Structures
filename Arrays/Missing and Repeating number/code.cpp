#include<bits/stdc++.h>
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size(); // Size of array 'a' 
    vector<int> count(n + 1, 0); // 'count' array
    for(int i = 0; i < n; ++i) {
        // Incrementing the frequency of current element
        ++count[a[i]];
    }
    int missing, repeating;
    for(int i = 1; i <= n; ++i) {
        if(count[i] == 0) missing = i;
        else if(count[i] == 2) repeating = i;
    }
    return {repeating, missing};

}
