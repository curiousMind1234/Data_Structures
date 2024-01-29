vector<int> Solution::getRow(int A) {
    vector<int> res;
    res.push_back(1);
    int curr = 1;
    for(int i=1;i<=A;i++){
        curr = curr * (A+1-i)/i;
        res.push_back(curr);
    }
    return res;
}
/*
This method is based on approach using Binomial Coefficient. We know that ith entry in a line number line is Binomial Coefficient C(line, i) and all lines start with value 1. The idea is to calculate C(line, i) using C(line, i-1). It can be calculated in O(1) time.

C(line, i) = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line – i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line – i + 1) / i
So C(line, i) can be calculated from C(line, i-1) in O(1) time


Time Complexity: O(N) 
Auxiliary Space: O(1)

*/

