 #define MAX 1000000
int maxOccured(int L[], int R[], int n, int maxx){

    //1st Approach Time Complexity is O(n * max) and Space Complexcity is O(M) for hashMap.
  
    int freq[100] = {0};
    for(int i=0;i<n;i++){
      for(int j=L[i];j<=R[i];j++){
          freq[j] += 1;
      }
    }
    int res =0;
    for(int i=0;i<100;i++){
        if(freq[i] > freq[res]){
            res = i;
        }
    }
    return res;


    //2nd Approach Time Complexity is O(n + MAX) and Space Complexcity is O(MAX) for hashMap.
    int freq[MAX] ;
    memset(freq, 0 , sizeof freq);
    
    int maxi = -1;
    
    for(int i=0;i<n;i++){
       freq[L[i]]+=1;
       freq[R[i]+1]-= 1;
       if(R[i] > maxi){
           maxi = R[i];
       }
    }
    int res =0;
    for(int i=0;i<maxi;i++){
        freq[i] = freq[i-1] + freq[i];
        if(freq[i] > freq[res]){
            res = i;
        }
    }
    return res;
}
