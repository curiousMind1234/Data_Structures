int median(int A[],int N) {
    sort(A,A+N);
    if(N%2 != 0){
        return A[N/2];
    }
    else{
        return (A[(N-1)/2] + A[N/2])/2.0;
    }
}
//Function to find mean of the array elements.
int mean(int A[],int N) {
    int sum = 0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    return sum/N;
}

/*
Time Complexity: O(N log(N)). log(N) for sorting
 Auxiliary Space: O(1).
*/
