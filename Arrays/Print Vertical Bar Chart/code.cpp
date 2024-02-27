#include <iostream>
using namespace std;
void pv(int *p , int n){
    int mx = p[0];
    for(int i=1;i<n;i++){
        if(p[i] >= mx){
            mx = p[i];
        }
    }
    
    for(int m=mx; m>=1;m--){
        for(int j=0;j<n;j++){
            if(p[j] >= m){
                cout << " *";   
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
int main()
{   int n;
    cin >> n;
    int *p = new int[n];
    for(int i=0; i<n;i++){
        cin >> p[i];
    }
    
    pv(p,n);

    return 0;
}
Input :  5
  1 2 5 3 4
  
Output: 
mx=5
  
     *    
     *   *
     * * *
   * * * *
 * * * * *


