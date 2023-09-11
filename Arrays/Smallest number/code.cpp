string getSmallest(long long N) {
    string res="";
    if(N == 1){
        return to_string(1);
    }
    for(int i=9;i>=2;i--){
        while(N % i == 0){
            N = N /i;
            res = to_string(i) + res;
        }
    }
    if(N != 1){
        return to_string(-1);
    }
    else{
        return res;
    }
}
