#include<bits/stdc++.h>
/*
class Solution {
public:
double power(double x, int n){
    if(n==0){
        return 1.0; # understand why 1.0 should be returned
    }
      if (n == 1)
    {
        return x;
    }
    
    if(n%2==0)
    {
        return power(x, n / 2) * power(x, n / 2); #Recursion was happening twice which caused in time limit exceeding

    }
    
        return x*power(x, n / 2) * power(x, n / 2);
    
    }

    double myPow(double x, int n) {
        if (n< 0)
    {
        return (1/power(x,-n)); #here if we multiply -1 with n it will convert back to negative
    }
    
    return power(x,n);
    
    }
};
*/


class Solution {
public:
double power(double x, long long int n){
    if(n==0){
        return 1.0;
    }
      if (n == 1)
    {
        return x;
    }
    double half=power(x, n / 2);
    
    if(n%2==0)
    {
        return half*half;
    }
    
        return x*half * half;
    
    }

    double myPow(double x, int n) {
    if (n< 0)
    {
        return (1/power(x, -1LL*n));
    }
    
    return power(x,n);
    
    }
};