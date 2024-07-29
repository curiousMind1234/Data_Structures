#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C){
    if(n==0) return;
    
    towerOfHanoi(n-1, A, C, B);
    cout <<"Move " << n << " from " << A << " to " << C <<endl;
    towerOfHanoi(n-1, B, A, C);
    
}
int main()
{
    towerOfHanoi(3,'A', 'B', 'C');
    return 0;
}

Output
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C

Time complexity: O(2N), There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(N times) is 2N
Auxiliary Space: O(N), Function call stack space



/////////////////////////////////////////////////////////////////////////////////
void solve(int n, int fromRod, int toRod, int auxRod, vector<vector<int>>& ans){
    if(n==0) return;

    solve(n-1, fromRod,auxRod,toRod,ans);
    ans.push_back({fromRod,toRod});
    solve(n-1, auxRod, toRod,fromRod,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;
    solve(n,1,3,2,ans);
    return ans;
}
