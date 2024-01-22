/*
The idea is to use Sridharacharya Formula for finding roots of quadratic equation ax2 + bx + c =0.
formula : -b +-sqrt(b*b -4*a*c)/(2*a);
The values of the roots depends on the term (b2 – 4ac) which is known as the discriminant (D). 
If D > 0:
       => This occurs when b2 > 4ac.
       => The roots are real and unequal.
       => The roots are {-b + √(b2 – 4ac)}/2a and {-b – √(b2 – 4ac)}/2a.
Else If D = 0:
       => This occurs when b2 = 4ac.
       => The roots are real and equal.
       => The roots are (-b/2a).
Else if D < 0:
       => This occurs when b2 < 4ac.
       => The roots are imaginary and unequal.
*/
vector<int> quadraticRoots(int a, int b, int c) {
    // code here
    vector<int> roots;
    int d = ((b*b) - (4 *a *c));
   
    if (d < 0) {
       roots.push_back(-1);
    }
    else {
      
        int  x1 = floor((-b + sqrt(d))/(2 * a));
        int  x2 = floor((-b - sqrt(d))/(2 * a));
        
        roots.push_back(max(x1, x2));
        roots.push_back(min(x1,x2));
    }
    return roots;      
}
Time Complexity: O(1), as we are performing simple mathematical and logical operations having constant time complexity.
Auxiliary Space: O(1), as we are not using any extra space, only some variables and a vector having maximum size of 2.
