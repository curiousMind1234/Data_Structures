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
