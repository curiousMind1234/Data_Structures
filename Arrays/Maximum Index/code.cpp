https://www.geeksforgeeks.org/batch/dsa-self-paced/track/DSASP-Arrays/problem/maximum-index-1587115620

int maxIndexDiff(int a[], int n) { 
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i]<=arr[j] && c < (j-i)){
                c = j-i;
            }
        }
        if(c == n-1-i) return c;
    }
    return c;

  /*
  TC : O(n*n)
  SC : O(n)
  */

  /**************************************************************************/
    int j=n-1;
    int i=0;
    int maxi =0;
    while( i<=j){
        if(a[i]<=a[j]){
            int diff=j-i;
            maxi=max(diff,maxi);
            i++;
            j=n-1;
        }
        else{
            j--;
        }
    }
    return maxi;
}
/*
TC : O(n)
SC : O(n)
*/
