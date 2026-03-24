//https://leetcode.com/problems/set-mismatch
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pos(int n) {
        if (n<0){
            return n*=-1;
        }
        return n;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
       for (int i =0;i<nums.size();i++) {
        if (nums[pos(nums[i])-1]<0) {
            dup = pos(nums[i]);
            break;
        }
        nums[pos(nums[i])-1]*=-1;
       }
       cout<<dup;
       for (int i =0;i<nums.size();i++) {
        if (nums[i]<0) {
            nums[i]*=-1;
        }
       }
       int sum = accumulate(nums.begin(),nums.end(),0);
       int n=nums.size();
       int expectedSum = (n*(n+1))/2;
       cout<<sum;
       int missing = expectedSum-(sum-dup);
       return {dup,missing};

    }
};
