#include <bits/stdc++.h> 
string stringSum(string &num1, string &num2) {
     int carry = 0;
     int i = num1.length()-1;
     int j= num2.length()-1;
     string result = "";
     while(i>=0 || j>=0 || carry >0){
        int n1 = (i>=0) ? num1[i--]-'0':0;
        int n2 = (j>=0) ? num2[j--]-'0':0;
        int sum = n1+n2+carry;
        carry = sum/10;

        result = to_string(sum%10) + result;
     }
     return result;
}
