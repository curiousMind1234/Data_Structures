/*
Following are the steps to find all prime factors: 
1. While n is divisible by 2, print 2 and divide n by 2.
2. After step 1, n must be odd. Now start a loop from i = 3 to square root of n. While i divides n, print i and divide n by i, increment i by 2 and continue.
3. If n is a prime number and is greater than 2, then n will not become 1 by above two steps. So print n if it is greater than 2.

*/

#include <iostream>
#include <cmath>

using namespace std;
//1st method:

void printPrime(int n){
    while(n%2 == 0){
        cout << 2 << " ";
        n = n /2;
    }
  // n must be odd at this point. So we can skip
	// one element (Note i = i +2)
    for(int i=3;i<sqrt(n);i=i+2){
        
        while(n%i == 0){
            cout << i << " ";
            n = n/ i;
        }
    }
  // This condition is to handle the case when n
	// is a prime number greater than 2
    if(n>2){
        cout << n << " ";
    }
}
//2nd method
void printPrime(int n){
    while(n%2 == 0){
        cout << 2 << " ";
        n = n /2;
    }
    while(n%3 == 0){
        cout << 3 << " ";
        n = n /3;
    }
    for(int i=5; i*i<=n;i=i+6){
        while(n%i == 0){
            cout << i << " ";
            n = n/ i;
        }
        while(n%(i+2) == 0){
            cout << i+2 << " ";
            n = n/ i+2;
        }
    }
    if(n>3) cout << n << " ";
}

int main()
{
    int n = 450;
    printPrime(n);
    return 0;
}
