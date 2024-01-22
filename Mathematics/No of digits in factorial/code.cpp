/*
* 10! = 3628800 which is approx 10^6,  10(whose power is 6) is already a double digit no. ,So no. of digit in                "factorial of  10" will be 6+1 i.e 7.
* same as 5!= 120 which is near by 10^2, so no. of digit in  factorial is  2+1
* for deal with only power of the no. we use log( )
     
* log(n!)=log(n*(n-1)*(n-2)*.....*1)
* log(n!)=log(n)+log(n-1)+.....log1

* log(5!)=log(120) i.e here log(120) is approx similar as       log(100) =log10(10^2) =2 (here in 120 ,2+1 will be the   number of digit)
* log(5!)=log(5*4*3*2*1) =log(5) +log(4) + log(3) +log(2) +log(1);
* conclusion is that "no of digit in factorial =  floor(log(n!) +1
*/

int digitsInFactorial(int n) {
    double res = 0;
    if(n==0 || n==1) return 1;
    for(int i=2;i<=n;i++){
        res+=log10(i);
    }
    return (floor(res)+1);
}

TC : O(n)
SC: O(1)
