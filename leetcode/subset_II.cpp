#include<bits/stdc++.h>
using namespace std;
/*class Solution {
public:
 void backtrack(vector<int>& nums,int i,vector<int>&sub,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        backtrack(nums,i+1,sub,ans);
        sub.pop_back();
        backtrack(nums,i+1,sub,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        set<vector<int>>st;
        backtrack(nums,0,sub,ans);
        for(auto &x:ans){
            st.insert(x);
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }    
    
};*/

// WHY WAS THE SORT FUNCTION USED?
// WHY USE REFERENCING MODE?
class Solution {
public:
 void backtrack(vector<int>& nums,int i,vector<int>&sub,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        backtrack(nums,i+1,sub,ans);
        sub.pop_back();
        backtrack(nums,i+1,sub,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>sub;
        set<vector<int>>st;
        backtrack(nums,0,sub,ans);
        for(auto &x:ans){
            st.insert(x);
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }    
    
};