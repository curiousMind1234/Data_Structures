/*LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers. 
For example, LCM of 15 and 20 is 60, and LCM of 5 and 7 is 35.
A simple solution is to find all prime factors of both numbers, then find union of all factors present in both numbers. Finally, return the product of elements in union.
An efficient solution is based on the below formula for LCM of two numbers ‘a’ and ‘b’. 
   a x b = LCM(a, b) * GCD (a, b)

   LCM(a, b) = (a x b) / GCD(a, b)
We have discussed function to find GCD of two numbers. Using GCD, we can find LCM. 
Below is the implementation of the above idea:
*/

#include <iostream>
using namespace std;

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
if (b == 0)
	return a;
return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
	return (a*b / gcd(a, b)) ;
}

// Driver program to test above function
int main()
{
	int a = 15, b = 20;
	cout <<"LCM of " << a << " and "
		<< b << " is " << lcm(a, b);
	return 0;
}

Output
LCM of 15 and 20 is 60
  
Time Complexity: O(log(min(a,b))
Auxiliary Space: O(log(min(a,b))
