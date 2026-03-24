#include<bits/stdc++.h>
using namespace std;
/*class Solution {
public:
vector<vector<int>> ans;
    void combination_sum(int k, int n, int i, vector<int> subset) {
        if (n == 0 && subset.size() == k){
            ans.push_back(subset);
            return;
        }
        if(n<i||(subset.size()>k)||i>9) return;
        subset.push_back(i);
        combination_sum(k,n-i,i+1,subset);
        subset.pop_back();
        combination_sum(k,n,i+1,subset);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        combination_sum(k,n,1,subset);
        return ans;
    }
};*/

// ab agar mera target 4 comb hai pr mere pas bs ek hi ele bacha hai toh check krne ka kya fayda
//isliye put 9-i+1<k-subset.size() for return

vector<vector<int>> ans;
    void combination_sum(int k, int n, int i, vector<int> subset) {
        if (n == 0 && subset.size() == k){
            ans.push_back(subset);
            return;
        }
        if(n<i||(subset.size()>k)||(9-i+1)<k-subset.size()||i>9) return;
        subset.push_back(i);
        combination_sum(k,n-i,i+1,subset);
        subset.pop_back();
        combination_sum(k,n,i+1,subset);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        combination_sum(k,n,1,subset);
        return ans;
    }

    /* Recursive function to find combinations
    void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans) {
        if(sum == 0 && nums.size() == k) {
            ans.push_back(nums);
            return; 
        }
        
        if(sum <= 0 || nums.size() > k) return; 

        
        for(int i = last; i <= 9; i++) {
        
            if(i <= sum) {
        
                nums.push_back(i); 
        
                func(sum - i, i + 1, nums, k, ans); 
        
                nums.pop_back(); 
            } else {
        
                break;
            }
        }
    } */